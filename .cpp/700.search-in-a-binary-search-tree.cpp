/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
 */

// @lc code=start
// 2022-08-19 submission
// 36/36 cases passed
// Runtime: 60 ms, faster than 60.29% of cpp online submissions.
// Memory Usage: 34.9 MB, less than 22.99% of cpp online submissions.
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        if (root->val == val) return root;
        return (root->val > val) ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};
// @lc code=end

// @lc code=start
// 2022-08-19 submission
// 36/36 cases passed
// Runtime: 37 ms, faster than 98.03% of cpp online submissions.
// Memory Usage: 34.8 MB, less than 22.99% of cpp online submissions.
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && root->val != val) {
            root = (root->val > val) ? root->left : root->right;
        }
        return root;
    }
};
// @lc code=end
