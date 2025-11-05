/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
// 1. 朴素 Dijkstra 算法
// 2025-03-24 submission
// 53/53 cases passed
// Runtime: 80 ms, faster than 76.01% of cpp online submissions.
// Memory Usage: 41.6 MB, less than 97.54% of cpp online submissions.
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = INT_MAX / 2;
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
        for (const vector<int>& time : times) {
            graph[time[0]][time[1]] = time[2];
        }
        vector<int> dist(n + 1, INF);
        vector<bool> visited(n + 1, false);
        dist[k] = 0;
        for (int i = 1; i <= n; ++i) {
            int t = -1;
            for (int j = 1; j <= n; ++j) {
                if (!visited[j] && (t == -1 || dist[j] < dist[t])) {
                    t = j;
                }
            }
            visited[t] = true;
            for (int j = 1; j <= n; ++j) {
                dist[j] = min(dist[j], dist[t] + graph[t][j]);
            }
        }
        int res = *max_element(dist.begin() + 1, dist.end());
        return res == INF ? -1 : res;
    }
};
// @lc code=end

// @lc code=start
// 2. 堆优化 Dijsktra 算法
// 2025-03-24 submission
// 53/53 cases passed
// Runtime: 79 ms, faster than 78.91% of cpp online submissions.
// Memory Usage: 44.2 MB, less than 85.02% of cpp online submissions.
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = INT_MAX / 2;
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& time : times) {
            graph[time[0]].emplace_back(time[1], time[2]);
        }
        vector<int> dist(n + 1, INF);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, k);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dist[u] < d) {
                continue;
            }
            for (auto& [v, w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        int res = *max_element(dist.begin() + 1, dist.end());
        return res == INF ? -1 : res;
    }
};
// @lc code=end
