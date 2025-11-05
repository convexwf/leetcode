/*
 * @lc app=leetcode id=156 lang=cpp
 *
 * [156] Binary Tree Upside Down
 */

// @lc code=start
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left) {
            return root;
        }

        TreeNode* newRoot = upsideDownBinaryTree(root->left);
        root->left->right = root;       // 原根节点变成新根节点的右孩子
        root->left->left = root->right; // 原右孩子变成新根节点的左孩子
        root->left = nullptr;           // 清空原左孩子
        root->right = nullptr;          // 清空原右孩子

        return newRoot;
    }
};
// @lc code=end
