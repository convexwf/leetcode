/*
 * @lc app=leetcode id=314 lang=cpp
 *
 * [314] Binary Tree Vertical Order Traversal
 */

// @lc code=start
// 1. dfs+有序字典
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        map<pair<int, int>, vector<int>> dic;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int x, int y) {
            if (!node) return;
            dic[{x, y}].push_back(node->val);
            dfs(node->left, x - 1, y + 1);
            dfs(node->right, x + 1, y + 1);
        };
        dfs(root, 0, 0);
        for (auto& [_, v] : dic) {
            res.push_back(v);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. bfs+有序字典
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        map<int, vector<int>> dic;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, x] = q.front();
            q.pop();
            dic[x].push_back(node->val);
            if (node->left) q.push({node->left, x - 1});
            if (node->right) q.push({node->right, x + 1});
        }
        for (auto& [_, v] : dic) {
            res.push_back(v);
        }
        return res;
    }
};
// @lc code=end
