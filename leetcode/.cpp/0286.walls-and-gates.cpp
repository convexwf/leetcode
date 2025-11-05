/*
 * @lc app=leetcode id=286 lang=cpp
 *
 * [286] Walls and Gates
 */

// @lc code=start
// 1. bfs
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) {
            return;
        }
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int dist = 0;
        while (!q.empty()) {
            int qsize = q.size();
            ++dist;
            while (qsize-- > 0) {
                pair<int, int>& p = q.front();
                q.pop();
                for (const auto& dir : dirs) {
                    int x = p.first + dir.first;
                    int y = p.second + dir.second;
                    if (x < 0 || x >= m || y < 0 || y >= n || rooms[x][y] != INT_MAX ||
                        rooms[x][y] <= dist) {
                        continue;
                    }
                    rooms[x][y] = dist;
                    q.push({x, y});
                }
            }
        }
    }
};
// @lc code=end
