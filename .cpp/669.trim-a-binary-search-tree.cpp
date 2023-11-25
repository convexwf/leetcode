/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
 */

// @lc code=start
// 1. 递归
// 2023-11-22 submission
// 78/78 cases passed
// Runtime: 12 ms, faster than 62.29% of cpp online submissions.
// Memory Usage: 24.5 MB, less than 5.15% of cpp online submissions.
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return nullptr;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
// @lc code=end

// @lc code=start
// 2. 迭代
// 2023-11-22 submission
// 78/78 cases passed
// Runtime: 12 ms, faster than 62.29% of cpp online submissions.
// Memory Usage: 24.1 MB, less than 72.89% of cpp online submissions.
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while (root && (root->val < low || root->val > high)) {
            root = root->val < low ? root->right : root->left;
        }
        if (!root) {
            return root;
        }
        TreeNode* node = root;
        while (node->left) {
            if (node->left->val < low) {
                node->left = node->left->right;
            }
            else {
                node = node->left;
            }
        }
        node = root;
        while (node->right) {
            if (node->right->val > high) {
                node->right = node->right->left;
            }
            else {
                node = node->right;
            }
        }
        return root;
    }
};
// @lc code=end
