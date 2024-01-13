/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
 */

// @lc code=start
// 1. 前序遍历
// 2024-01-10 submission
// 58/58 cases passed
// Runtime: 4 ms, faster than 59.01% of cpp online submissions.
// Memory Usage: 14.7 MB, less than 77.62% of cpp online submissions.
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth = 0;
        return dfs(root, depth);
    }

private:
    TreeNode* dfs(TreeNode* root, int& depth) {
        if (!root) {
            depth = 0;
            return nullptr;
        }
        int leftDepth = 0, rightDepth = 0;
        TreeNode* left = dfs(root->left, leftDepth);
        TreeNode* right = dfs(root->right, rightDepth);
        depth = max(leftDepth, rightDepth) + 1;
        if (leftDepth == rightDepth) {
            return root;
        }
        else if (leftDepth > rightDepth) {
            return left;
        }
        else {
            return right;
        }
    }
};
// @lc code=end
