/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

// @lc code=start
// 1. 递归
// 2020-07-08 submission
// 8/8 cases passed
// Runtime: 23 ms, faster than 60.84% of cpp online submissions.
// Memory Usage: 16.5 MB, less than 20.85% of cpp online submissions.
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = generateTrees(start, i - 1);
            vector<TreeNode*> right = generateTrees(i + 1, end);
            for (TreeNode*& l : left) {
                for (TreeNode*& r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 递归+记忆数组
// 2023-01-14 submission
// 8/8 cases passed
// Runtime: 23 ms, faster than 60.84% of cpp online submissions.
// Memory Usage: 12.5 MB, less than 95.51% of cpp online submissions.
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        vector<vector<vector<TreeNode*>>> memo(n + 1, vector<vector<TreeNode*>>(n + 1));
        return generateTrees(1, n, memo);
    }

    vector<TreeNode*> generateTrees(int start, int end, vector<vector<vector<TreeNode*>>>& memo) {
        if (start > end) {
            return {nullptr};
        }
        if (!memo[start][end].empty()) {
            return memo[start][end];
        }
        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = generateTrees(start, i - 1, memo);
            vector<TreeNode*> right = generateTrees(i + 1, end, memo);
            for (auto& l : left) {
                for (auto& r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return memo[start][end] = res;
    }
};
// @lc code=end
