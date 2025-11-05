/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
// 1. 深度计算
// 2018-07-22 submission
// 228/228 cases passed
// Runtime: 15 ms, faster than 73.63% of cpp online submissions.
// Memory Usage: 21 MB, less than 30.19% of cpp online submissions.
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
    bool isBalanced(TreeNode *root) {
        return checkDepth(root) != -1;
    }

    int checkDepth(TreeNode *root) {
        if (!root) return 0;
        int left = checkDepth(root->left);
        int right = checkDepth(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
};
// @lc code=end
