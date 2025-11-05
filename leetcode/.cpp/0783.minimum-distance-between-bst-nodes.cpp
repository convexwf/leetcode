/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
 */

// @lc code=start
// 1. 中序遍历
// 2023-09-07 submission
// 49/49 cases passed
// Runtime: 5 ms, faster than 26.72% of cpp online submissions.
// Memory Usage: 9.7 MB, less than 86.34% of cpp online submissions.
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
    int minDiffInBST(TreeNode* root) {
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
// 49/49 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 9.7 MB, less than 51.84% of cpp online submissions.
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
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
