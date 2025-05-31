/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 */

// @lc code=start
// 1. dfs
// 2025-05-30 submission
// 155/155 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 18.2 MB, less than 39.8% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(grid, row, col, grid[row][col], visited);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] < 0) {
                    grid[i][j] = color;
                }
            }
        }
        return grid;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int originalColor,
             vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        const vector<int> directions = {1, 0, -1, 0, 1};
        visited[row][col] = true;
        grid[row][col] = -grid[row][col];
        for (int i = 0; i < 4; ++i) {
            int newRow = row + directions[i];
            int newCol = col + directions[i + 1];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                !visited[newRow][newCol] && grid[newRow][newCol] == originalColor) {
                dfs(grid, newRow, newCol, originalColor, visited);
            }
        }
        if (row > 0 && row < m - 1 && col > 0 && col < n - 1) {
            bool isBorder = false;
            for (int i = 0; i < 4; ++i) {
                int newRow = row + directions[i];
                int newCol = col + directions[i + 1];
                if (abs(grid[newRow][newCol]) != abs(originalColor)) {
                    isBorder = true;
                    break;
                }
            }
            if (!isBorder) {
                grid[row][col] = originalColor;
            }
        }
    }
};
// @lc code=end
