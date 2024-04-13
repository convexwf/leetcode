/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 */

// @lc code=start
// 1. DFS
// 2023-06-16 submission
// 78/78 cases passed
// Runtime: 4 ms, faster than 98.24% of cpp online submissions.
// Memory Usage:  MB, less than 96.8% of cpp online submissions.
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode* root, int level, vector<int>& res) {
        if (!root) return;
        if (level == res.size())
            res.push_back(root->val);
        else
            res[level] = max(res[level], root->val);
        dfs(root->left, level + 1, res);
        dfs(root->right, level + 1, res);
    }
};
// @lc code=end

// @lc code=start
// 2. BFS
// 2023-06-16 submission
// 78/78 cases passed
// Runtime: 12 ms, faster than 72.76% of cpp online submissions.
// Memory Usage: 22.1 MB, less than 84.93% of cpp online submissions.
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int maxVal = INT_MIN;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                maxVal = max(maxVal, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(maxVal);
        }
        return res;
    }
};
// @lc code=end