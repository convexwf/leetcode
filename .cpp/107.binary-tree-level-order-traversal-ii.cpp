/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 */

// @lc code=start
// 2023-01-14 submission
// 34/34 cases passed
// Runtime: 8 ms, faster than 44.52% of cpp online submissions.
// Memory Usage: 13.4 MB, less than 8.3% of cpp online submissions.
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        pushOrder(root, res, 0);
        reverse(res.begin(), res.end());
        return res;
        // return vector<vector<int>> (res.rbegin(), res.rend());
    }

    void pushOrder(TreeNode* root, vector<vector<int>>& vec, int depth) {
        if (root == nullptr) return;
        if (vec.size() == depth) vec.push_back({});
        vec[depth].push_back(root->val);
        pushOrder(root->left, vec, depth + 1);
        pushOrder(root->right, vec, depth + 1);
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 34/34 cases passed
// Runtime: 29 ms, faster than 5.09% of cpp online submissions.
// Memory Usage: 12.5 MB, less than 86.81% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            vector<int> oneLevel;
            for (int i = q.size(); i > 0; --i) {
                TreeNode* t = q.front();
                q.pop();
                oneLevel.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.insert(res.begin(), oneLevel);
        }
        return res;
    }
};
// @lc code=end
