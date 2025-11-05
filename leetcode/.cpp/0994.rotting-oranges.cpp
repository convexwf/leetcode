/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
// 1. bfs
// 2023-07-11 submission
// 306/306 cases passed
// Runtime: 7 ms, faster than 73.05% of cpp online submissions.
// Memory Usage: 13.1 MB, less than 71.27% of cpp online submissions.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++fresh;
                }
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        int res = 0;
        vector<int> dirs = {0, 1, 0, -1, 0};
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                int x = cur.first;
                int y = cur.second;
                for (int j = 0; j < 4; ++j) {
                    int nx = x + dirs[j];
                    int ny = y + dirs[j + 1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        --fresh;
                    }
                }
            }
            ++res;
        }
        return fresh == 0 ? res : -1;
    }
};
// @lc code=end
