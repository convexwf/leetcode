/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
// 1. 并查集
// 2023-05-30 submission
// 39/39 cases passed
// Runtime: 8 ms, faster than 69.25% of cpp online submissions.
// Memory Usage: 8.7 MB, less than 82.85% of cpp online submissions.
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        for (auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            if (find(parent, node1) != find(parent, node2)) {
                unionSet(parent, node1, node2);
            }
            else {
                return edge;
            }
        }
        return {};
    }

    int find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = find(parent, parent[index]);
        }
        return parent[index];
    }

    void unionSet(vector<int>& parent, int index1, int index2) {
        parent[find(parent, index1)] = find(parent, index2);
    }
};
// @lc code=end

// @lc code=start
// 2. DFS
// 2023-05-30 submission
// 39/39 cases passed
// Runtime: 12 ms, faster than 35.81% of cpp online submissions.
// Memory Usage: 9.4 MB, less than 27.68% of cpp online submissions.
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<pair<int, int>>> graph(n + 1);
        vector<bool> visited(n + 1, false); // 记录边是否访问过
        // 邻接表(存储边下标和邻接点)
        for (int i = 0; i < n; ++i) {
            graph[edges[i][0]].push_back({i, edges[i][1]});
            graph[edges[i][1]].push_back({i, edges[i][0]});
        }
        // 从后往前遍历，找到第一条多余的边
        for (int i = n - 1; i >= 0; --i) {
            visited[i] = true;
            if (dfs(graph, visited, edges[i][0], edges[i][1])) {
                return edges[i];
            }
            visited[i] = false;
        }
        return {};
    }

    bool dfs(vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int start, int target) {
        if (start == target) {
            return true;
        }
        for (auto& next : graph[start]) {
            if (!visited[next.first]) {
                visited[next.first] = true;
                if (dfs(graph, visited, next.second, target)) {
                    return true;
                }
                visited[next.first] = false;
            }
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 3. BFS
// 2023-05-30 submission
// 39/39 cases passed
// Runtime: 9 ms, faster than 52.37% of cpp online submissions.
// Memory Usage: 9.7 MB, less than 20.76% of cpp online submissions.
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1, 0);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            ++indegree[edge[0]];
            ++indegree[edge[1]];
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    --indegree[neighbor];
                    if (indegree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (indegree[edges[i][0]] > 1 && indegree[edges[i][1]] > 1) {
                return edges[i];
            }
        }
        return {};
    }
};
// @lc code=end