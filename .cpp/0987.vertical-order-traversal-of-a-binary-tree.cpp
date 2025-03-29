/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
 */

// @lc code=start
// 1. dfs+排序
// 2025-03-26 submission
// 34/34 cases passed
// Runtime: 3 ms, faster than 41.97% of cpp online submissions.
// Memory Usage: 17.3 MB, less than 5.39% of cpp online submissions.
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> coords;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int x, int y) {
            if (!node) return;
            coords.push_back({x, y, node->val});
            dfs(node->left, x - 1, y + 1);
            dfs(node->right, x + 1, y + 1);
        };
        dfs(root, 0, 0);
        sort(coords.begin(), coords.end());

        vector<vector<int>> res;
        int curX = coords[0][0] - 1;
        for (const vector<int>& coord : coords) {
            if (coord[0] != curX) {
                curX = coord[0];
                res.push_back({});
            }
            res.back().push_back(coord[2]);
        }
        return res;
    }
};
// @lc code=end
