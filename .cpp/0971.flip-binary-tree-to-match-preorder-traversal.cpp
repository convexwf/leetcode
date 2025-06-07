/*
 * @lc app=leetcode id=971 lang=cpp
 *
 * [971] Flip Binary Tree To Match Preorder Traversal
 */

// @lc code=start
// 1. dfs
// 2025-06-03 submission
// 104/104 cases passed
// Runtime: 3 ms, faster than 8.43% of cpp online submissions.
// Memory Usage: 16.8 MB, less than 70.22% of cpp online submissions.
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> result;
        int index = 0;
        if (dfs(root, voyage, index, result)) {
            return result;
        }
        else {
            return {-1};
        }
    }

    bool dfs(TreeNode* node, vector<int>& voyage, int& index, vector<int>& result) {
        if (!node) {
            return true;
        }
        if (node->val != voyage[index++]) {
            return false;
        }

        if (node->left && node->left->val != voyage[index]) {
            result.push_back(node->val);
            swap(node->left, node->right);
        }

        return dfs(node->left, voyage, index, result) && dfs(node->right, voyage, index, result);
    }
};
// @lc code=end
