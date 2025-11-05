/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 */

// @lc code=start
// 1. 前序遍历+哈希表
// 2022-08-19 submission
// 422/422 cases passed
// Runtime: 102 ms, faster than 10.82% of cpp online submissions.
// Memory Usage: 38.9 MB, less than 22.94% of cpp online submissions.
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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return traverse(root, k, st);
    }
    bool traverse(TreeNode* node, int k, unordered_set<int>& st) {
        if (!node) return false;
        if (st.count(k - node->val)) return true;
        st.insert(node->val);
        return traverse(node->left, k, st) || traverse(node->right, k, st);
    }
};
// @lc code=end
