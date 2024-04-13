/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 */

// @lc code=start
// 1. 递归
// 2023-09-12 submission
// 58/58 cases passed
// Runtime: 18 ms, faster than 43.45% of cpp online submissions.
// Memory Usage: 24.5 MB, less than 56.7% of cpp online submissions.
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;
        int maxCount = 0;
        dfs(root, m, maxCount);
        vector<int> res;
        for (auto& [sum, count] : m) {
            if (count == maxCount) {
                res.push_back(sum);
            }
        }
        return res;
    }

private:
    int dfs(TreeNode* root, unordered_map<int, int>& m, int& maxCount) {
        if (!root) {
            return 0;
        }
        int left = dfs(root->left, m, maxCount);
        int right = dfs(root->right, m, maxCount);
        int sum = left + right + root->val;
        ++m[sum];
        maxCount = max(maxCount, m[sum]);
        return sum;
    }
};
// @lc code=end
