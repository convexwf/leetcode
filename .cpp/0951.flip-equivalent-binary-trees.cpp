/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
 */

// @lc code=start
// 1. 递归
// 2025-03-03 submission
// 81/81 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 15.4 MB, less than 72.68% of cpp online submissions.
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        }
        if (!root1 || !root2 || root1->val != root2->val) {
            return false;
        }
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};
// @lc code=end
