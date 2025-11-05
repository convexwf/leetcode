/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
 */

// @lc code=start
// 1. 递归
// 2023-10-13 submission
// 63/63 cases passed
// Runtime: 6 ms, faster than 44.96% of cpp online submissions.
// Memory Usage: 16.8 MB, less than 59.4% of cpp online submissions.
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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }

private:
    void dfs(TreeNode* root, int num, int& sum) {
        if (root == nullptr) {
            return;
        }
        num = num * 2 + root->val;
        if (root->left == root->right) {
            sum += num;
            return;
        }
        dfs(root->left, num, sum);
        dfs(root->right, num, sum);
    }
};
// @lc code=end
