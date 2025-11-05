/*
 * @lc app=leetcode id=366 lang=cpp
 *
 * [366] Find Leaves of Binary Tree
 */

// @lc code=start
// 1. 递归
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, vector<vector<int>>& res) {
        if (!root) return 0;
        int level = max(dfs(root->left, res), dfs(root->right, res)) + 1;
        if (res.size() < level) res.push_back({});
        res[level - 1].push_back(root->val);
        return level;
    }
};
// @lc code=end
