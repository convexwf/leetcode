/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start
// 2018-07-12 submission
// 34/34 cases passed
// Runtime: 4 ms, faster than 74.32% of C++ online submissions.
// Memory Usage: 13.3 MB, less than 13.61% of C++ online submissions.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        pushOrder(root, vec, 0);
        return vec;
    }

    void pushOrder(TreeNode*root, vector<vector<int>>& vec, int depth) {
        if(root == NULL) return;
        if (vec.size() == depth) vec.push_back({});
        vec[depth].push_back(root->val);
        pushOrder(root->left, vec, depth+1);
        pushOrder(root->right, vec, depth+1);
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 34/34 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 12.7 MB, less than 33.25% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            vector<int> oneLevel;
            for (int i = q.size(); i > 0; --i) {
                TreeNode *t = q.front(); q.pop();
                oneLevel.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(oneLevel);
        }
        return res;
    }
};
// @lc code=end