/*
 * @lc app=leetcode id=998 lang=cpp
 *
 * [998] Maximum Binary Tree II
 */

// @lc code=start
// 1. 递归
// 2024-01-12 submission
// 75/75 cases passed
// Runtime: 4 ms, faster than 61.29% of cpp online submissions.
// Memory Usage:  MB, less than 22.58% of cpp online submissions.
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root == nullptr || val > root->val) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};
// @lc code=end

// @lc code=start
// 2. 迭代
// 2024-01-12 submission
// 75/75 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 13.8 MB, less than 62.67% of cpp online submissions.
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (root == nullptr || val > root->val) {
            node->left = root;
            return node;
        }
        TreeNode* cur = root;
        while (cur->right != nullptr && cur->right->val > val) {
            cur = cur->right;
        }
        node->left = cur->right;
        cur->right = node;
        return root;
    }
};
// @lc code=end
