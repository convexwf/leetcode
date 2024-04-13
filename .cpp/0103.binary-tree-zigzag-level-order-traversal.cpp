/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */

// @lc code=start
// 2023-01-31 submission
// 33/33 cases passed
// Runtime: 7 ms, faster than 31.59% of cpp online submissions.
// Memory Usage: 13 MB, less than 5.18% of cpp online submissions.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, 0, res);
        return res;
    }

    void helper(TreeNode* node, int level, vector<vector<int>>& res) {
        if (!node) return;
        if (res.size() <= level) {
            res.push_back({});
        }
        vector<int>& oneLevel = res[level];
        if (level % 2 == 0)
            oneLevel.push_back(node->val);
        else
            oneLevel.insert(oneLevel.begin(), node->val);
        helper(node->left, level + 1, res);
        helper(node->right, level + 1, res);
    }
};
// @lc code=end

// @lc code=start
// 2023-01-31 submission
// 33/33 cases passed
// Runtime: 3 ms, faster than 76.22% of cpp online submissions.
// Memory Usage: 12.2 MB, less than 17% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        bool leftToRight = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> oneLevel(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* t = q.front();
                q.pop();
                int idx = leftToRight ? i : (size - 1 - i);
                oneLevel[idx] = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            leftToRight = !leftToRight;
            res.push_back(oneLevel);
        }
        return res;
    }
};
// @lc code=end
