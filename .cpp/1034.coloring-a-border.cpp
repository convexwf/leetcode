/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(grid, row, col, color, grid[row][col], visited);
        return grid;
    }

    bool dfs(vector<vector<int>>& grid, int row, int col, int color, int oldColor,
             vector<vector<bool>>& visited) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return false;
        if (grid[row][col] != oldColor) return false;
        if (visited[row][col]) return grid[row][col] == oldColor;
        visited[row][col] = true;
        bool isBorder = false;
        isBorder = isBorder || !dfs(grid, row - 1, col, color, oldColor, visited);
        isBorder = isBorder || !dfs(grid, row + 1, col, color, oldColor, visited);
        isBorder = isBorder || !dfs(grid, row, col - 1, color, oldColor, visited);
        isBorder = isBorder || !dfs(grid, row, col + 1, color, oldColor, visited);
        if (isBorder) grid[row][col] = color;
        return isBorder;
    }
};
// @lc code=end
