/*
 * @lc app=leetcode id=840 lang=cpp
 *
 * [840] Magic Squares In Grid
 */

// @lc code=start
// 1. 暴力枚举
// 2023-09-15 submission
// 93/93 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.5 MB, less than 56.6% of cpp online submissions.
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                if (grid[i + 1][j + 1] != 5) continue;
                if (isMagicSquare(grid, i, j)) ++res;
            }
        }
        return res;
    }

    bool isMagicSquare(vector<vector<int>>& grid, int i, int j) {
        vector<int> count(10, 0);
        for (int r = i; r < i + 3; ++r) {
            for (int c = j; c < j + 3; ++c) {
                if (grid[r][c] < 1 || grid[r][c] > 9) return false;
                ++count[grid[r][c]];
                if (count[grid[r][c]] > 1) return false;
            }
        }
        return grid[i][j] + grid[i][j + 1] + grid[i][j + 2] == 15 &&
               grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] == 15 &&
               grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] == 15 &&
               grid[i][j] + grid[i + 1][j] + grid[i + 2][j] == 15 &&
               grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] == 15 &&
               grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] == 15 &&
               grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == 15;
    }
};
// @lc code=end
