/*
 * @lc app=leetcode id=510 lang=cpp
 *
 * [510] Inorder Successor in BST II
 */

// @lc code=start
// 1. 模拟
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            node = node->right;
            while (node->left) {
                node = node->left;
            }
            return node;
        }
        while (node->parent && node->parent->right == node) {
            node = node->parent;
        }
        return node->parent;
    }
};

// @lc code=end
