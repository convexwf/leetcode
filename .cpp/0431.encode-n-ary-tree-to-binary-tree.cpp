/*
 * @lc app=leetcode id=431 lang=cpp
 *
 * [431] Encode N-ary Tree to Binary Tree
 */

// @lc code=start
// 1. 模拟
class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(root->val);
        if (!root->children.empty()) {
            node->left = encode(root->children[0]);
        }

        TreeNode* cur = node->left;
        for (int i = 1; i < root->children.size(); i++) {
            cur->right = encode(root->children[i]);
            cur = cur->right;
        }

        return node;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* node = new Node(root->val);
        TreeNode* cur = root->left;
        while (cur != nullptr) {
            node->children.push_back(decode(cur));
            cur = cur->right;
        }

        return node;
    }
};
// @lc code=end
