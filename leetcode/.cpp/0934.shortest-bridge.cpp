/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */

// @lc code=start
// 1. DFS+BFS
// 2023-07-25 submission
// 97/97 cases passed
// Runtime: 58 ms, faster than 61.29% of cpp online submissions.
// Memory Usage: 18.7 MB, less than 86.57% of cpp online submissions.
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (found) break;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q, dirs);
                    found = true;
                    break;
                }
            }
        }
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto& dir : dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 2) continue;
                    if (grid[nx][ny] == 1) return step;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            ++step;
        }
        return -1;
    }

private:
    void dfs(vector<vector<int>>& grid, int x, int y, queue<pair<int, int>>& q,
             vector<vector<int>>& dirs) {
        int n = grid.size();
        if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 1) return;
        grid[x][y] = 2;
        q.push({x, y});
        for (auto& dir : dirs) {
            dfs(grid, x + dir[0], y + dir[1], q, dirs);
        }
    }
};
// @lc code=end
