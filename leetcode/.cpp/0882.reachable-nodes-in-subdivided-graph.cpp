/*
 * @lc app=leetcode id=882 lang=cpp
 *
 * [882] Reachable Nodes In Subdivided Graph
 */

// @lc code=start
// 1. Djikstra 算法
// 2025-06-04 submission
// 50/50 cases passed
// Runtime: 24 ms, faster than 84.45% of cpp online submissions.
// Memory Usage: 48.6 MB, less than 73.17% of cpp online submissions.
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> graph(n);
        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1], cnt = edge[2];
            graph[u].emplace_back(v, cnt + 1);
            graph[v].emplace_back(u, cnt + 1);
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0); // (distance, node)

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            for (const auto& [v, weight] : graph[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.emplace(dist[v], v);
                }
            }
        }

        int reachableCount = 0;
        for (int i = 0; i < n; ++i) {
            if (dist[i] <= maxMoves) {
                reachableCount++;
            }
        }

        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1], cnt = edge[2];
            int reachableFromU = max(0, maxMoves - dist[u]);
            int reachableFromV = max(0, maxMoves - dist[v]);
            reachableCount += min(cnt, reachableFromU + reachableFromV);
        }

        return reachableCount;
    }
};
// @lc code=end
