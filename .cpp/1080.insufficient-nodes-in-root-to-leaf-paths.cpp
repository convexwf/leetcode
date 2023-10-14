/*
 * @lc app=leetcode id=1080 lang=cpp
 *
 * [1080] Insufficient Nodes in Root to Leaf Paths
 */

// @lc code=start
// 1. 递归
// 2023-10-11 submission
// 116/116 cases passed
// Runtime: 34 ms, faster than 59.37% of cpp online submissions.
// Memory Usage: 33.3 MB, less than 41.16% of cpp online submissions.
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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (root->left == root->right) {
            return root->val < limit ? nullptr : root;
        }
        if (root->left) {
            root->left = sufficientSubset(root->left, limit - root->val);
        }
        if (root->right) {
            root->right = sufficientSubset(root->right, limit - root->val);
        }
        return root->left == root->right ? nullptr : root;
    }
};
// @lc code=end
