/*
 * @lc app=leetcode id=317 lang=cpp
 *
 * [317] Shortest Distance from All Buildings
 */

// @lc code=start
// 1. bfs
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> reach(m, vector<int>(n));
        vector<pair<int, int>> buildings;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto bfs = [&](int x, int y) {
            queue<pair<int, int>> q;
            q.push({x, y});
            vector<vector<bool>> visited(m, vector<bool>(n));
            int level = 1;
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; ++i) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (auto& [dx, dy] : directions) {
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0 &&
                            !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            dist[nx][ny] += level;
                            reach[nx][ny]++;
                            q.push({nx, ny});
                        }
                    }
                }
                level++;
            }
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    buildings.push_back({i, j});
                }
            }
        }
        for (auto& [x, y] : buildings) {
            bfs(x, y);
        }
        int res = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && reach[i][j] == buildings.size()) {
                    res = min(res, dist[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end
