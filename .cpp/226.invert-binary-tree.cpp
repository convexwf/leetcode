/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

// @lc code=start
// 2022-11-14 submission
// 77/77 cases passed
// Runtime: 3 ms, faster than 73.23% of C++ online submissions.
// Memory Usage: 9.7 MB, less than 37.68% of C++ online submissions.
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* l_child = invertTree(root->left);
        TreeNode* r_child = invertTree(root->right);
        root->left = r_child;
        root->right = l_child;
        return root;
    }
};
// @lc code=end

// @lc code=start
// 2022-11-14 submission
// 77/77 cases passed
// Runtime: 6 ms, faster than 32.33% of C++ online submissions.
// Memory Usage: 9.8 MB, less than 5.31% of C++ online submissions.
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            TreeNode *tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};
// @lc code=end