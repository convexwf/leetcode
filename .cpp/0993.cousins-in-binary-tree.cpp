/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
 */

// @lc code=start
// 1. 层序遍历
// 2023-09-11 submission
// 105/105 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 11.2 MB, less than 23.6% of cpp online submissions.
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return false;
        queue<TreeNode*> q;
        q.push(root);
        bool x_exist = false, y_exist = false;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->val == x) x_exist = true;
                if (node->val == y) y_exist = true;
                if (node->left != nullptr && node->right != nullptr) {
                    if (node->left->val == x && node->right->val == y) return false;
                    if (node->left->val == y && node->right->val == x) return false;
                }
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            if (x_exist && y_exist)
                return true;
            else if (x_exist || y_exist)
                return false;
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2. 先序遍历
// 2023-09-11 submission
// 105/105 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 39.97% of cpp online submissions.
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, nullptr, x, y, 0);
        return xDepth == yDepth && xParent != yParent;
    }

private:
    TreeNode* xParent = nullptr;
    TreeNode* yParent = nullptr;
    int xDepth = 0;
    int yDepth = 0;
    void dfs(TreeNode* root, TreeNode* parent, int x, int y, int depth) {
        if (root == nullptr) return;
        if (root->val == x) {
            xParent = parent;
            xDepth = depth;
        }
        if (root->val == y) {
            yParent = parent;
            yDepth = depth;
        }
        dfs(root->left, root, x, y, depth + 1);
        dfs(root->right, root, x, y, depth + 1);
    }
};
// @lc code=end
