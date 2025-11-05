/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
 */

// @lc code=start
// 1. dfs
// 2023-12-27 submission
// 70/70 cases passed
// Runtime: 3 ms, faster than 97.03% of cpp online submissions.
// Memory Usage: 20.1 MB, less than 62.42% of cpp online submissions.
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
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        dfs(root, "", ans);
        return ans;
    }

    void dfs(TreeNode* root, string path, string& ans) {
        if (root == nullptr) {
            return;
        }
        path = string(1, 'a' + root->val) + path;
        if (root->left == nullptr && root->right == nullptr) {
            if (ans == "" || path < ans) {
                ans = path;
            }
        }
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }
};
// @lc code=end
