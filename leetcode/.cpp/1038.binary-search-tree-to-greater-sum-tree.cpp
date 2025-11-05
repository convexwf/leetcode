/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
 */

// @lc code=start
// 1. 反向中序遍历
// 2023-12-22 submission
// 30/30 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.5 MB, less than 73.14% of cpp online submissions.
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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        convert(root, sum);
        return root;
    }

private:
    void convert(TreeNode* root, int& sum) {
        if (root == nullptr) return;
        convert(root->right, sum);
        sum += root->val;
        root->val = sum;
        convert(root->left, sum);
    }
};
// @lc code=end
