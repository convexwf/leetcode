/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
 */

// @lc code=start
// 1. 递归
// 2021-03-10 submission
// 182/182 cases passed
// Runtime: 34 ms, faster than 94.75% of cpp online submissions.
// Memory Usage: 33 MB, less than 25.25% of cpp online submissions.
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        TreeNode* t = new TreeNode(root1->val + root2->val);
        t->left = mergeTrees(root1->left, root2->left);
        t->right = mergeTrees(root1->right, root2->right);
        return t;
    }
};
// @lc code=end
