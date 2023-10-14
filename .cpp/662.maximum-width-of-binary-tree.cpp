/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
 */

// @lc code=start
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        long ans = 0;
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int qsize = q.size();
            long left = q.front().second, right = left;
            for (int i = 0; i < qsize; ++i) {
                auto [node, pos] = q.front();
                q.pop();
                right = pos;
                if (node->left) q.push({node->left, pos * 2});
                if (node->right) q.push({node->right, pos * 2 + 1});
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end
