/*
 * @lc app=leetcode id=298 lang=cpp
 *
 * [298] Binary Tree Longest Consecutive Sequence
 */

// @lc code=start
// 1. dfs
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, res, 1, root->val);
        return res;
    }

    void dfs(TreeNode* root, int& res, int cur, int target) {
        if (!root) return;
        if (root->val == target) {
            cur++;
        }
        else {
            cur = 1;
        }
        res = max(res, cur);
        dfs(root->left, res, cur, root->val + 1);
        dfs(root->right, res, cur, root->val + 1);
    }
};
// @lc code=end
