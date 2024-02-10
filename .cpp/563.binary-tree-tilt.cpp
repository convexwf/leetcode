/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
 */

// @lc code=start
// 2022-11-15 submission
// 77/77 cases passed
// Runtime: 20 ms, faster than 88.56% of C++ online submissions.
// Memory Usage: 23.7 MB, less than 35.34% of C++ online submissions.
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
    int findTilt(TreeNode* root) {
        int result = 0;
        search(root, result);
        return result;
    }

    int search(TreeNode* root, int& tilt_sum) {
        if (!root) return 0;
        int left = search(root->left, tilt_sum);
        int right = search(root->right, tilt_sum);
        tilt_sum += abs(left-right);
        return root->val + left + right;
    }

};
// @lc code=end