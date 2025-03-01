/*
 * @lc app=leetcode id=545 lang=cpp
 *
 * [545] Boundary of Binary Tree
 */

// @lc code=start
// 1. 模拟
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        res.push_back(root->val);
        if (root->left) {
            leftBoundary(root->left, res);
        }
        if (root->left || root->right) {
            leaves(root, res);
        }
        vector<int> right;
        if (root->right) {
            rightBoundary(root->right, right);
        }
        res.insert(res.end(), right.rbegin(), right.rend());
        return res;
    }

    void leftBoundary(TreeNode* root, vector<int>& res) {
        if (!root || (!root->left && !root->right)) return;
        res.push_back(root->val);
        if (root->left) {
            leftBoundary(root->left, res);
        }
        else {
            leftBoundary(root->right, res);
        }
    }

    void rightBoundary(TreeNode* root, vector<int>& res) {
        if (!root || (!root->left && !root->right)) return;
        res.push_back(root->val);
        if (root->right) {
            rightBoundary(root->right, res);
        }
        else {
            rightBoundary(root->left, res);
        }
    }

    void leaves(TreeNode* root, vector<int>& res) {
        if (!root) return;
        if (!root->left && !root->right) {
            res.push_back(root->val);
        }
        leaves(root->left, res);
        leaves(root->right, res);
    }
};
// @lc code=end
