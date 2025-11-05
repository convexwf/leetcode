/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 */

// @lc code=start
// 1. DFS
// 2023-12-27 submission
// 111/111 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 72.51% of cpp online submissions.
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size() - 1);
    }

    TreeNode* dfs(vector<int>& preorder, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[start]);
        int i = start + 1;
        while (i <= end && preorder[i] < preorder[start]) {
            ++i;
        }
        root->left = dfs(preorder, start + 1, i - 1);
        root->right = dfs(preorder, i, end);
        return root;
    }
};
// @lc code=end
