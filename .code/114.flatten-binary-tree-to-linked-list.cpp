/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 */

// @lc code=start
// 2020-09-16 submission
// 225/225 cases passed
// Runtime: 7 ms, faster than 86.43% of C++ online submissions.
// Memory Usage: 12.7 MB, less than 37.29% of C++ online submissions.
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
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);

        TreeNode* right = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right) root = root->right;
        root->right = right;
    }
};
// @lc code=end

// @lc code=start
// 2022-11-17 submission
// 225/225 cases passed
// Runtime: 8 ms, faster than 76.6% of C++ online submissions.
// Memory Usage: 12.7 MB, less than 37.29% of C++ online submissions.
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *p = cur->left;
                while (p->right) p = p->right;
                p->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
// @lc code=end