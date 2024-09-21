/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
 */

// @lc code=start
// 1. dfs
// 2023-07-10 submission
// 39/39 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.1 MB, less than 8.72% of cpp online submissions.
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
    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr) return -1;
        int ans = -1;
        int minVal = root->val;
        dfs(root, minVal, ans);
        return ans;
    }
    void dfs(TreeNode* root, int minVal, int& ans) {
        if (root == nullptr) return;
        if (root->val > minVal) {
            if (ans == -1) {
                ans = root->val;
            }
            else {
                ans = min(ans, root->val);
            }
        }
        if (root->val <= ans || ans == -1) {
            dfs(root->left, minVal, ans);
            dfs(root->right, minVal, ans);
        }
    }
};
// @lc code=end
