/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
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
