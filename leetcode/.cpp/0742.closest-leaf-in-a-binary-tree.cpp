/*
 * @lc app=leetcode id=742 lang=cpp
 *
 * [742] Closest Leaf in a Binary Tree
 */

// @lc code=start
// 1. bfs+dfs+建图
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> leaves;

    void dfs(TreeNode* root, TreeNode* parent) {
        if (!root) return;
        if (parent) {
            graph[root->val].push_back(parent->val);
            graph[parent->val].push_back(root->val);
        }
        if (!root->left && !root->right) {
            leaves.insert(root->val);
        }
        dfs(root->left, root);
        dfs(root->right, root);
    }

    void bfs(int target) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(target);
        visited.insert(target);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (leaves.count(node)) {
                ans = node;
                break;
            }
            for (int neighbor : graph[node]) {
                if (visited.count(neighbor)) continue;
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    int findClosestLeaf(TreeNode* root, int k) {
        dfs(root, nullptr);
        bfs();
        return ans;
    }
};
// @lc code=end
