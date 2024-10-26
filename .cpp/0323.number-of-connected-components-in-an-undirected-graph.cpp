/*
 * @lc app=leetcode id=323 lang=cpp
 *
 * [323] Number of Connected Components in an Undirected Graph
 */

// @lc code=start
// 1. dfs
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++res;
                dfs(graph, visited, i);
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int i) {
        if (visited[i]) return;
        visited[i] = true;
        for (int j : graph[i]) {
            dfs(graph, visited, j);
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 并查集
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        int count = n;
        for (const auto& edge : edges) {
            int x = find(parent, edge[0]);
            int y = find(parent, edge[1]);
            if (x != y) {
                parent[x] = y;
                count--;
            }
        }
        return count;
    }

    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
};
// @lc code=end
