/*
 * @lc app=leetcode id=270 lang=cpp
 *
 * [270] Closest Binary Search Tree Value
 */

// @lc code=start
// 1. 递归
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        dfs(root, target, res);
        return res;
    }

    void dfs(TreeNode* node, double target, int& res) {
        if (!node) return;
        if (node->val == target) {
            res = node->val;
            return;
        }
        if (node->val < target) {
            dfs(node->right, target, res);
        }
        else {
            dfs(node->left, target, res);
        }
        if (abs(node->val - target) < abs(res - target)) {
            res = node->val;
        }
    }
};
// @lc code=end
