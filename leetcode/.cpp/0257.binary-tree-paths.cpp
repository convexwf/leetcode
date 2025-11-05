/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */

// @lc code=start
// 1. DFS
// 2023-01-14 submission
// 208/208 cases passed
// Runtime: 7 ms, faster than 52.16% of cpp online submissions.
// Memory Usage: 12.5 MB, less than 90.16% of cpp online submissions.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root) helper(root, "", res);
        return res;
    }
    void helper(TreeNode* node, string out, vector<string>& res) {
        if (!node->left && !node->right) res.push_back(out + to_string(node->val));
        if (node->left) helper(node->left, out + to_string(node->val) + "->", res);
        if (node->right) helper(node->right, out + to_string(node->val) + "->", res);
    }
};
// @lc code=end

// @lc code=start
// 2. DFS-另一种写法
// 2023-01-14 submission
// 208/208 cases passed
// Runtime: 8 ms, faster than 41.77% of cpp online submissions.
// Memory Usage: 13.6 MB, less than 26.05% of cpp online submissions.
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        if (!root->left && !root->right) return {to_string(root->val)};
        vector<string> res;
        for (string str : binaryTreePaths(root->left)) {
            res.push_back(to_string(root->val) + "->" + str);
        }
        for (string str : binaryTreePaths(root->right)) {
            res.push_back(to_string(root->val) + "->" + str);
        }
        return res;
    }
};
// @lc code=end
