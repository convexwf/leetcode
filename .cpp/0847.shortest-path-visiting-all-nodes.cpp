/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
// 1. bfs+位操作+状态压缩
// 2025-06-06 submission
// 54/54 cases passed
// Runtime: 211 ms, faster than 8.58% of cpp online submissions.
// Memory Usage: 26.2 MB, less than 17.16% of cpp online submissions.
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int, int>> q;
        unordered_set<string> visited;

        for (int i = 0; i < n; ++i) {
            int state = 1 << i;
            q.push({i, state});
            visited.insert(to_string(i) + "," + to_string(state));
        }

        int steps = 0;

        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; ++i) {
                auto [node, state] = q.front();
                q.pop();

                // check if all nodes have been visited
                if (state == (1 << n) - 1) {
                    return steps;
                }

                for (int next_node : graph[node]) {
                    int next_state = state | (1 << next_node);
                    string key = to_string(next_node) + "," + to_string(next_state);

                    if (!visited.count(key)) {
                        visited.insert(key);
                        q.push({next_node, next_state});
                    }
                }
            }
            ++steps;
        }

        return -1; // should not reach here
    }
};
// @lc code=end

// @lc code=start
// 2. bfs+状态压缩+最小堆
// 2025-03-06 submission
// 54/54 cases passed
// Runtime: 3 ms, faster than 99.2% of cpp online submissions.
// Memory Usage: 12.5 MB, less than 96.7% of cpp online submissions.
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        unordered_set<int> seen;
        int n = graph.size();
        for (int i = 0; i < n; i++) {
            pq.push({0, i, 1 << i});
            seen.insert((1 << i) | (1 << (n + i)));
        }

        while (!pq.empty()) {
            const vector<int> top = pq.top();
            pq.pop();
            int dist = top[0], u = top[1], mask = top[2];

            if (mask == (1 << n) - 1) {
                return dist;
            }

            for (int v : graph[u]) {
                if (seen.count(mask | (1 << (n + v)))) {
                    continue;
                }
                seen.insert(mask | (1 << v));
                pq.push({dist + 1, v, mask | (1 << v)});
            }
        }
        return -1;
    }
};
// @lc code=end
