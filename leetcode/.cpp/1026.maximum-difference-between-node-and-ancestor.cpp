/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
 */

// @lc code=start
// 1. dfs
// 2024-12-11 submission
// 30/30 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 13.5 MB, less than 28.32% of cpp online submissions.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }

    int dfs(TreeNode* root, int mn, int mx) {
        if (root == nullptr) {
            return mx - mn;
        }
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        return max(dfs(root->left, mn, mx), dfs(root->right, mn, mx));
    }
};
// @lc code=end
