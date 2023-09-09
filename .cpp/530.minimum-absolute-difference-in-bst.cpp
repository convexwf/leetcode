/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 */

// @lc code=start
// 1. 中序遍历
// 2023-09-07 submission
// 189/189 cases passed
// Runtime: 8 ms, faster than 91.81% of cpp online submissions.
// Memory Usage: 25.2 MB, less than 72.26% of cpp online submissions.
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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int prev = -1;
        inorder(root, prev, minDiff);
        return minDiff;
    }

private:
    void inorder(TreeNode* root, int& prev, int& minDiff) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, prev, minDiff);
        if (prev != -1) {
            minDiff = min(minDiff, root->val - prev);
        }
        prev = root->val;
        inorder(root->right, prev, minDiff);
    }
};
// @lc code=end

// @lc code=start
// 2. 先序遍历
// 2023-09-07 submission
// 189/189 cases passed
// Runtime: 7 ms, faster than 97.38% of cpp online submissions.
// Memory Usage: 25.2 MB, less than 72.26% of cpp online submissions.
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        helper(root, INT_MIN, INT_MAX, res);
        return res;
    }
    void helper(TreeNode* node, int low, int high, int& res) {
        if (!node) return;
        if (low != INT_MIN) res = min(res, node->val - low);
        if (high != INT_MAX) res = min(res, high - node->val);
        helper(node->left, low, node->val, res);
        helper(node->right, node->val, high, res);
    }
};
// @lc code=end
