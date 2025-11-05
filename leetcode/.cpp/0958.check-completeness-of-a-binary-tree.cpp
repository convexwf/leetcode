/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
 */

// @lc code=start
// 1. 层序遍历
// 2023-08-15 submission
// 120/120 cases passed
// Runtime: 7 ms, faster than 33.3% of cpp online submissions.
// Memory Usage: 10.6 MB, less than 6.05% of cpp online submissions.
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
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> q{{root}};
        while (q.front() != nullptr) {
            TreeNode* node = q.front();
            q.pop();
            q.push(node->left);
            q.push(node->right);
        }
        while (!q.empty() && q.front() == nullptr) {
            q.pop();
        }
        return q.empty();
    }
};
// class Solution {
// public:
//     bool isCompleteTree(TreeNode* root) {
//         if (root == nullptr) return true;
//         queue<TreeNode*> q;
//         q.push(root);
//         bool flag = false;
//         while (!q.empty()) {
//             TreeNode* node = q.front();
//             q.pop();
//             if (node == nullptr) {
//                 flag = true;
//             } else {
//                 if (flag) return false;
//                 q.push(node->left);
//                 q.push(node->right);
//             }
//         }
//         return true;
//     }
// };
// @lc code=end
