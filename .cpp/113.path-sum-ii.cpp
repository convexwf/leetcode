/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */

// @lc code=start
// 1. 前序遍历
// 2022-07-30 submission
// 115/115 cases passed
// Runtime: 7 ms, faster than 95.93% of cpp online submissions.
// Memory Usage: 19.7 MB, less than 92.78% of cpp online submissions.
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> current;
        traverse(res, current, root, targetSum);
        return res;
    }

    void traverse(vector<vector<int>>& candidates, vector<int>& current, TreeNode* root, int rest) {
        if (!root) return;
        current.push_back(root->val);
        if (!root->left && !root->right && root->val == rest) {
            candidates.push_back(current);
        }
        if (root->left) traverse(candidates, current, root->left, rest - root->val);
        if (root->right) traverse(candidates, current, root->right, rest - root->val);
        current.pop_back();
    }
};
// @lc code=end
