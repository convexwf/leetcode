/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 */

// @lc code=start
// 1. 哈希表+前缀和+递归
// 2023-11-03 submission
// 128/128 cases passed
// Runtime: 12 ms, faster than 88.63% of cpp online submissions.
// Memory Usage: 21.6 MB, less than 24.05% of cpp online submissions.
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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefixSum;
        prefixSum[0] = 1;
        return dfs(root, prefixSum, 0, targetSum);
    }

    int dfs(TreeNode* root, unordered_map<long, int>& prefixSum, long curSum, int targetSum) {
        if (!root) {
            return 0;
        }
        curSum += root->val;
        int res = prefixSum[curSum - targetSum];
        ++prefixSum[curSum];
        res += dfs(root->left, prefixSum, curSum, targetSum);
        res += dfs(root->right, prefixSum, curSum, targetSum);
        --prefixSum[curSum];
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 递归
// 2023-11-03 submission
// 128/128 cases passed
// Runtime: 26 ms, faster than 32.04% of cpp online submissions.
// Memory Usage: 16.3 MB, less than 71.93% of cpp online submissions.
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return sumUp(root, 0, targetSum) + pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
    int sumUp(TreeNode* node, long pre, int targetSum) {
        if (!node) return 0;
        long cur = pre + node->val;
        return (cur == targetSum) + sumUp(node->left, cur, targetSum) +
               sumUp(node->right, cur, targetSum);
    }
};
// @lc code=end
