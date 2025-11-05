/*
 * @lc app=leetcode id=1059 lang=cpp
 *
 * [1059] All Paths from Source Lead to Destination
 */

// @lc code=start
// 1. 记忆化搜索
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (vector<int> > &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<int> f(n);
        return dfs(graph, f, source, destination);
    }

    bool dfs(vector<vector<int>>& graph, vector<int>& f, int u, int destination) {
        if (f[u] != 0) {
            return f[u] == 1;
        }
        if (graph[u].empty()) {
            return u == destination;
        }
        f[u] = -1;
        for (int v : graph[u]) {
            if (!dfs(graph, f, v, destination)) {
                return false;
            }
        }
        f[u] = 1;
        return true;
    }
};
// @lc code=end
