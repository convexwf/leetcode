/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
// 1. DFS
// 2023-12-21 submission
// 30/30 cases passed
// Runtime: 466 ms, faster than 74.21% of cpp online submissions.
// Memory Usage: 246.5 MB, less than 26.75% of cpp online submissions.
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return dfs(graph, visited, source, destination);
    }

private:
    bool dfs(const vector<vector<int>>& graph, vector<bool>& visited, int source, int destination) {
        if (source == destination) {
            return true;
        }
        visited[source] = true;
        for (const auto& neighbor : graph[source]) {
            if (!visited[neighbor]) {
                if (dfs(graph, visited, neighbor, destination)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2. BFS
// 2023-12-21 submission
// 30/30 cases passed
// Runtime: 446 ms, faster than 80.48% of cpp online submissions.
// Memory Usage:  MB, less than 80.76% of cpp online submissions.
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == destination) {
                return true;
            }
            for (int next : graph[cur]) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 3. 并查集
// 2023-12-21 submission
// 30/30 cases passed
// Runtime: 301 ms, faster than 98.42% of cpp online submissions.
// Memory Usage:  MB, less than 98.81% of cpp online submissions.
class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for (auto& edge : edges) {
            int x = find(parent, edge[0]);
            int y = find(parent, edge[1]);
            if (x != y) {
                parent[x] = y;
            }
        }
        return find(parent, source) == find(parent, destination);
    }
};
// @lc code=end
