/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */

// @lc code=start
// 2023-01-14 submission
// 216/216 cases passed
// Runtime: 3 ms, faster than 82.91% of cpp online submissions.
// Memory Usage: 12.2 MB, less than 27.55% of cpp online submissions.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            res.push_back(q.back()->val);
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 216/216 cases passed
// Runtime: 7 ms, faster than 42.05% of cpp online submissions.
// Memory Usage: 11.7 MB, less than 97.73% of cpp online submissions.
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        helper(root, 1, ret);
        return ret;
    }

    void helper(TreeNode* node, int level, vector<int>& values) {
        if (!node) return;
        if (values.size() < level) values.push_back(node->val);
        helper(node->right, level + 1, values);
        helper(node->left, level + 1, values);
    }
};
// @lc code=end
