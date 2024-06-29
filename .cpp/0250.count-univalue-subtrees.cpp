/*
 * @lc app=leetcode id=250 lang=cpp
 *
 * [250] Count Univalue Subtrees
 */

// @lc code=start
// 1. dfs
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

    bool dfs(TreeNode* root, int& res) {
        if (root == nullptr) {
            return true;
        }
        bool left = dfs(root->left, res);
        bool right = dfs(root->right, res);
        if (left && right) {
            if ((root->left == nullptr || root->left->val == root->val) &&
                (root->right == nullptr || root->right->val == root->val)) {
                res++;
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
