/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 */

// @lc code=start
// 1. 递归
// 2024-12-26 submission
// 124/124 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 22.4 MB, less than 76.44% of cpp online submissions.
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
    int rob(TreeNode* root) {
        pair<int, int> res = dfs(root);
        return max(res.first, res.second);
    }

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        int rob = root->val + left.first + right.first;
        int not_rob = max(left.first, left.second) + max(right.first, right.second);
        return {not_rob, rob};
    }
};
// @lc code=end
