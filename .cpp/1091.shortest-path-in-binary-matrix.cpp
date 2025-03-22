/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
// 1. bfs
// 2025-03-21 submission
// 90/90 cases passed
// Runtime: 13 ms, faster than 95.56% of cpp online submissions.
// Memory Usage: 23.9 MB, less than 74.94% of cpp online submissions.
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        if (n == 1) {
            return 1;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                    {0, 1},   {1, -1}, {1, 0},  {1, 1}};
        int res = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();
                for (const vector<int>& dir : dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        if (nx == n - 1 && ny == n - 1) {
                            return res + 1;
                        }
                        q.push({nx, ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};
// @lc code=end
