/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
 */

// @lc code=start
// 1. 递归中序遍历+dummy节点
// 2024-08-13 submission
// 38/38 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 10.4 MB, less than 45.36% of cpp online submissions.
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        dummy->right = root;
        TreeNode* pre = dummy;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (node == nullptr) {
                return;
            }
            inorder(node->left);
            pre->right = node;
            node->left = nullptr;
            pre = node;
            inorder(node->right);
        };
        inorder(root);
        return dummy->right;
    }
};
// @lc code=end
