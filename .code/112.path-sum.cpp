/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

// @lc code=start
// 2022-07-30 submission
// 117/117 cases passed
// Runtime: 15 ms, faster than 68.33% of C++ online submissions.
// Memory Usage: 21.3 MB, less than 74.49% of C++ online submissions.
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) {
            return sum == root->val;
        }
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};
// @lc code=end