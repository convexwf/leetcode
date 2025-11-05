/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 */

// @lc code=start
// 1. 后续遍历+序列化
// 2023-09-12 submission
// 175/175 cases passed
// Runtime: 32 ms, faster than 31.39% of cpp online submissions.
// Memory Usage: 42.8 MB, less than 57.81% of cpp online submissions.
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> m;
        dfs(root, m, res);
        return res;
    }
    string dfs(TreeNode* root, unordered_map<string, int>& m, vector<TreeNode*>& res) {
        if (!root) return "#";
        string str =
            to_string(root->val) + "," + dfs(root->left, m, res) + "," + dfs(root->right, m, res);
        if (m[str] == 1) res.push_back(root);
        ++m[str];
        return str;
    }
};
// @lc code=end
