/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 */

// @lc code=start
// 2021-12-21 submission
// 66/66 cases passed
// Runtime: 19 ms, faster than 61.5% of cpp online submissions.
// Memory Usage: 22.3 MB, less than 93.47% of cpp online submissions.
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        if (root) q.push(root);
        while (!q.empty()) {
            int q_size = q.size();
            double level_sum = 0;
            for (int i = 0; i < q_size; i++) {
                level_sum += q.front()->val;
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            res.push_back(level_sum / q_size);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-31 submission
// 66/66 cases passed
// Runtime: 21 ms, faster than 48.74% of cpp online submissions.
// Memory Usage: 22.4 MB, less than 75.45% of cpp online submissions.
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res, cnt;
        helper(root, 0, cnt, res);
        for (int i = 0; i < res.size(); ++i) {
            res[i] /= cnt[i];
        }
        return res;
    }

    void helper(TreeNode* node, int level, vector<double>& cnt, vector<double>& res) {
        if (!node) return;
        if (res.size() <= level) {
            res.push_back(0);
            cnt.push_back(0);
        }
        res[level] += node->val;
        ++cnt[level];
        helper(node->left, level + 1, cnt, res);
        helper(node->right, level + 1, cnt, res);
    }
};
// @lc code=end
