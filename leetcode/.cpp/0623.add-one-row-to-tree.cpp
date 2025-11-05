/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
 */

// @lc code=start
// 1. 层序遍历
// 2023-06-26 submission
// 109/109 cases passed
// Runtime: 16 ms, faster than 90.43% of cpp online submissions.
// Memory Usage:  MB, less than 25.47% of cpp online submissions.
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                if (depth == d - 1) {
                    TreeNode* left = node->left;
                    TreeNode* right = node->right;
                    node->left = new TreeNode(v);
                    node->left->left = left;
                    node->right = new TreeNode(v);
                    node->right->right = right;
                }
                else {
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            depth++;
        }
        return root;
    }
};
// @lc code=end

// @lc code=start
// 2. DFS
// 2023-06-26 submission
// 109/109 cases passed
// Runtime: 16 ms, faster than 90.43% of cpp online submissions.
// Memory Usage: 24.8 MB, less than 98.38% of cpp online submissions.
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        dfs(root, v, d, 1);
        return root;
    }

private:
    void dfs(TreeNode* root, int v, int d, int depth) {
        if (root == nullptr) return;
        if (depth == d - 1) {
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = new TreeNode(v);
            root->right = new TreeNode(v);
            root->left->left = left;
            root->right->right = right;
            return;
        }
        dfs(root->left, v, d, depth + 1);
        dfs(root->right, v, d, depth + 1);
    }
};
// @lc code=end