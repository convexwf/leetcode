/*
 * @lc app=leetcode id=776 lang=cpp
 *
 * [776] Split BST
 */

// @lc code=start
// 1. 递归
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        if (root == nullptr) {
            return {nullptr, nullptr};
        }
        if (root->val <= target) {
            vector<TreeNode*> res = splitBST(root->right, target);
            root->right = res[0];
            return {root, res[1]};
        }
        else {
            vector<TreeNode*> res = splitBST(root->left, target);
            root->left = res[1];
            return {res[0], root};
        }
    }
};
// @lc code=end
