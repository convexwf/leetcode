/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
 */

// @lc code=start
// 1. 层序遍历
// 2024-01-08 submission
// 116/116 cases passed
// Runtime: 4 ms, faster than 86.53% of cpp online submissions.
// Memory Usage:  MB, less than 39.07% of cpp online submissions.
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = 0;
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int qsize = q.size();
            int left = q.front().second, right = left;
            for (int i = 0; i < qsize; ++i) {
                auto [node, pos] = q.front();
                q.pop();
                right = pos;
                if (node->left) q.push({node->left, (pos - left) * 2});
                if (node->right) q.push({node->right, (pos - left) * 2 + 1});
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 2. 前序遍历
// 2024-01-08 submission
// 116/116 cases passed
// Runtime: 4 ms, faster than 86.53% of cpp online submissions.
// Memory Usage: 18.5 MB, less than 6.22% of cpp online submissions.
class Solution {
public:
    using ull = unsigned long long;

    int widthOfBinaryTree(TreeNode* root) {
        ull ans = 1;
        vector<int> left;
        dfs(root, 0, 0, left, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, int level, ull pos, vector<int>& left, ull& ans) {
        if (!root) return;
        if (level == left.size()) {
            left.push_back(pos);
        }
        else {
            ans = max(ans, pos - left[level] + 1);
        }
        dfs(root->left, level + 1, pos * 2, left, ans);
        dfs(root->right, level + 1, pos * 2 + 1, left, ans);
    }
};
// @lc code=end
