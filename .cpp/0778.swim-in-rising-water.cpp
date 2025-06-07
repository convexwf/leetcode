/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
// 1. bfs+最小堆
// 2025-06-04 submission
// 43/43 cases passed
// Runtime: 7 ms, faster than 62.09% of cpp online submissions.
// Memory Usage: 12.8 MB, less than 71.48% of cpp online submissions.
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});

        const vector<int> directions = {0, 1, 0, -1, 0}; // Right, Down, Left, Up
        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;

            if (x == n - 1 && y == n - 1) {
                return time;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i], ny = y + directions[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int newTime = max(time, grid[nx][ny]);
                    if (newTime < dist[nx][ny]) {
                        dist[nx][ny] = newTime;
                        pq.push({newTime, {nx, ny}});
                    }
                }
            }
        }

        return -1; // This line should never be reached
    }
};
// @lc code=end
