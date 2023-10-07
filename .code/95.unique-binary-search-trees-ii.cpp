/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

// @lc code=start
// 2020-07-08 submission
// 8/8 cases passed
// Runtime: 23 ms, faster than 60.84% of C++ online submissions.
// Memory Usage: 16.5 MB, less than 20.85% of C++ online submissions.
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
        if (n == 0) return {};
        return helper(1, n);
    }

    vector<TreeNode*> helper(int left, int right) {
        vector<TreeNode*> res, left_res, right_res;
        for (int pivot = left; pivot <= right; pivot++) {
            if (left == pivot) left_res = vector<TreeNode*>{nullptr};
            else left_res = helper(left, pivot - 1);
            if (right == pivot) right_res = vector<TreeNode*>{nullptr};
            else right_res = helper(pivot + 1, right);

            for (int i = 0; i < left_res.size()*right_res.size(); i++) {
                TreeNode* new_node = new TreeNode(pivot);
                new_node->left = left_res[i % left_res.size()];
                new_node->right = right_res[i / left_res.size()];
                res.push_back(new_node);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 8/8 cases passed
// Runtime: 23 ms, faster than 60.84% of C++ online submissions.
// Memory Usage: 12.5 MB, less than 95.51% of C++ online submissions.
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<vector<vector<TreeNode*>>> memo(n, vector<vector<TreeNode*>>(n));
        return helper(1, n, memo);
    }
    vector<TreeNode*> helper(int start, int end, vector<vector<vector<TreeNode*>>>& memo) {
        if (start > end) return {nullptr};
        if (!memo[start - 1][end - 1].empty()) return memo[start - 1][end - 1];
        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            auto left = helper(start, i - 1, memo), right = helper(i + 1, end, memo);
            for (auto a : left) {
                for (auto b : right) {
                    TreeNode *node = new TreeNode(i);
                    node->left = a;
                    node->right = b;
                    res.push_back(node);
                }
            }
        }
        return memo[start - 1][end - 1] = res;
    }
};
// @lc code=end