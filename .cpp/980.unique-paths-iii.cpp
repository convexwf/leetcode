/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
// 1. DFS
// 2024-02-04 submission
// 39/39 cases passed
// Runtime: 5 ms, faster than 28.79% of cpp online submissions.
// Memory Usage: 9.3 MB, less than 18.92% of cpp online submissions.
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int count = 0, start = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0)
                    ++count;
                else if (grid[i][j] == 1)
                    start = i * n + j;
            }
        }
        vector<bool> visited(m * n, false);
        int res = 0;
        dfs(grid, visited, res, start, count + 1);
        return res;
    }

private:
    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& grid, vector<bool>& visited, int& result, int pos,
             int leftCount) {
        int m = grid.size(), n = grid[0].size();
        int x = pos / n, y = pos % n;
        if (grid[x][y] == 2) {
            if (leftCount == 0) {
                ++result;
            }
            return;
        }
        visited[pos] = true;
        for (auto& dir : dirs) {
            int nx = x + dir[0], ny = y + dir[1];
            int newpos = nx * n + ny;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[newpos] || grid[nx][ny] == -1)
                continue;
            dfs(grid, visited, result, newpos, leftCount - 1);
        }
        visited[pos] = false;
    }
};
// @lc code=end
