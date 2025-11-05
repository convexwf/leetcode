/*
 * @lc app=leetcode id=549 lang=cpp
 *
 * [549] Binary Tree Longest Consecutive Sequence II
 */

// @lc code=start
// 1. dfs
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        function<vector<int>(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return vector<int>{0, 0};
            }
            vector<int> left = dfs(root->left);
            vector<int> right = dfs(root->right);
            int inc = 1, dec = 1;
            if (root->left) {
                if (root->left->val == root->val + 1) {
                    inc = left[0] + 1;
                }
                else if (root->left->val == root->val - 1) {
                    dec = left[1] + 1;
                }
            }
            if (root->right) {
                if (root->right->val == root->val + 1) {
                    inc = max(inc, right[0] + 1);
                }
                else if (root->right->val == root->val - 1) {
                    dec = max(dec, right[1] + 1);
                }
            }
            res = max(res, inc + dec - 1);
            return vector<int>{inc, dec};
        };
        dfs(root);
        return res;
    }
};
// @lc code=end
