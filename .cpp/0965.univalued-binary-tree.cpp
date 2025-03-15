/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
 */

// @lc code=start
// 1. 递归
// 2023-11-29 submission
// 72/72 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 10.2 MB, less than 83.97% of cpp online submissions.
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
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (root->left != nullptr && root->val != root->left->val) {
            return false;
        }
        if (root->right != nullptr && root->val != root->right->val) {
            return false;
        }
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
// @lc code=end
