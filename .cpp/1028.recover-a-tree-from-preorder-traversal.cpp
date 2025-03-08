/*
 * @lc app=leetcode id=1028 lang=cpp
 *
 * [1028] Recover a Tree From Preorder Traversal
 */

// @lc code=start
// 1. 递归
// 2025-03-04 submission
// 105/105 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 21.7 MB, less than 37.92% of cpp online submissions.
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
    TreeNode* recoverFromPreorder(string traversal) {
        int pivot = 0;
        return recoverFromPreorder(traversal, pivot, 0);
    }

    TreeNode* recoverFromPreorder(const string& traversal, int& pivot, int depth) {
        if (pivot >= traversal.length()) {
            return nullptr;
        }

        int currentDepth = 0;
        while (pivot < traversal.length() && traversal[pivot] == '-') {
            currentDepth++;
            pivot++;
        }
        if (currentDepth != depth) {
            pivot -= currentDepth;
            return nullptr;
        }

        int number = 0;
        while (pivot < traversal.length() && isdigit(traversal[pivot])) {
            number = number * 10 + (traversal[pivot] - '0');
            pivot++;
        }

        TreeNode* node = new TreeNode(number);
        node->left = recoverFromPreorder(traversal, pivot, depth + 1);
        node->right = recoverFromPreorder(traversal, pivot, depth + 1);
        return node;
    }
};
// @lc code=end
