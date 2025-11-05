/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 */

// @lc code=start
// 1. 递归+标志位
// 2020-12-11 submission
// 100/100 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 13.4 MB, less than 48.73% of cpp online submissions.
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
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }

    int helper(TreeNode* root, bool is_left) {
        if (!root) return 0;
        if (!root->left && !root->right) return is_left ? root->val : 0;
        return helper(root->left, true) + helper(root->right, false);
    }
};
// @lc code=end

// @lc code=start
// 2. 递归+父节点判断
// 2023-01-14 submission
// 100/100 cases passed
// Runtime: 4 ms, faster than 72.47% of cpp online submissions.
// Memory Usage: 13.4 MB, less than 48.73% of cpp online submissions.
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (root->left && !root->left->left && !root->left->right) {
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
// @lc code=end
