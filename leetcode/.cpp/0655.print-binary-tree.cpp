/*
 * @lc app=leetcode id=655 lang=cpp
 *
 * [655] Print Binary Tree
 */

// @lc code=start
// 1. 先序遍历
// 2023-07-07 submission
// 73/73 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 99.59% of cpp online submissions.
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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int rows = height, cols = (1 << height) - 1;
        vector<vector<string>> res(rows, vector<string>(cols, ""));
        preorder(root, res, 0, 0, cols - 1);
        return res;
    }

    void preorder(TreeNode* root, vector<vector<string>>& res, int row, int left, int right) {
        if (!root) return;
        res[row][(left + right) / 2] = to_string(root->val);
        preorder(root->left, res, row + 1, left, (left + right) / 2 - 1);
        preorder(root->right, res, row + 1, (left + right) / 2 + 1, right);
    }

    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};
// @lc code=end
