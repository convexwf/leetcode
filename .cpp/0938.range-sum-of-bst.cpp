/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 */

// @lc code=start
// 1. dfs
// 2024-11-20 submission
// 41/41 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 97.29% of cpp online submissions.
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        if (root->val >= low && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high) +
                   rangeSumBST(root->right, low, high);
        }
        else if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        else {
            return rangeSumBST(root->left, low, high);
        }
    }
};
// @lc code=end
