/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 */

// @lc code=start
// 1. 递归
// 2023-07-11 submission
// 71/71 cases passed
// Runtime: 180 ms, faster than 10.03% of cpp online submissions.
// Memory Usage: 71.7 MB, less than 62.98% of cpp online submissions.
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
    int longestUnivaluePath(TreeNode* root) {
        int maxLen = 0;
        dfs(root, maxLen);
        return maxLen;
    }
    int dfs(TreeNode* root, int& maxLen) {
        if (!root) return 0;
        int left = dfs(root->left, maxLen);
        int right = dfs(root->right, maxLen);
        if (root->left && root->left->val == root->val)
            left += 1;
        else
            left = 0;
        if (root->right && root->right->val == root->val)
            right += 1;
        else
            right = 0;
        maxLen = max(maxLen, left + right);
        return max(left, right);
    }
};
// @lc code=end

// @lc code=start
// 2. 递归优化
// 2023-07-12 submission
// 71/71 cases passed
// Runtime: 131 ms, faster than 98.41% of cpp online submissions.
// Memory Usage: 71.8 MB, less than 26.99% of cpp online submissions.
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int sub = max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
        return max(sub, helper(root->left, root->val) + helper(root->right, root->val));
    }
    int helper(TreeNode* node, int parent) {
        if (!node || node->val != parent) return 0;
        return 1 + max(helper(node->left, node->val), helper(node->right, node->val));
    }
};
// @lc code=end
