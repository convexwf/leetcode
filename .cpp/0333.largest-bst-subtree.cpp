/*
 * @lc app=leetcode id=333 lang=cpp
 *
 * [333] Largest BST Subtree
 */

// @lc code=start
// 1. 递归
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

    vector<int> dfs(TreeNode* root, int& res) {
        if (!root) return {1, 0, 0};
        vector<int> left = dfs(root->left, res);
        vector<int> right = dfs(root->right, res);
        if (left[0] > 0 && right[0] > 0 && (!root->left || root->val > left[2]) &&
            (!root->right || root->val < right[1])) {
            int sum = left[0] + right[0] + 1;
            res = max(res, sum);
            return {sum, root->left ? left[1] : root->val, root->right ? right[2] : root->val};
        }
        return {0, 0, 0};
    }
};
// @lc code=end
