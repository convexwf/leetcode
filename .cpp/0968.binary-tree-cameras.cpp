/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
 */

// @lc code=start
// 1. 记忆化搜索
// 2024-01-22 submission
// 171/171 cases passed
// Runtime: 45 ms, faster than 5.3% of cpp online submissions.
// Memory Usage: 32.5 MB, less than 5.07% of cpp online submissions.
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
    int minCameraCover(TreeNode* root) {
        unordered_map<TreeNode*, unordered_map<int, int>> memo;
        return min(dfs(root, 0, memo), dfs(root, 1, memo));
    }

    inline int min3(const int& a, const int& b, const int& c) {
        return min(a, min(b, c));
    }

    int dfs(TreeNode* node, int status, unordered_map<TreeNode*, unordered_map<int, int>>& memo) {
        if (node == nullptr) {
            return status == 0 ? INT_MAX / 2 : 0;
        }
        if (memo.count(node) && memo[node].count(status)) {
            return memo[node][status];
        }
        int left0 = dfs(node->left, 0, memo);
        int left1 = dfs(node->left, 1, memo);
        int left2 = dfs(node->left, 2, memo);
        int right0 = dfs(node->right, 0, memo);
        int right1 = dfs(node->right, 1, memo);
        int right2 = dfs(node->right, 2, memo);
        int res = 0;
        if (status == 0) {
            res = min3(left0, left1, left2) + min3(right0, right1, right2) + 1;
        }
        else if (status == 1) {
            res = min3(left0 + right0, left0 + right1, left1 + right0);
        }
        else {
            res = left1 + right1;
        }
        return memo[node][status] = res;
    }
};
// @lc code=end
