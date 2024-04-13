/*
 * @lc app=leetcode id=883 lang=cpp
 *
 * [883] Projection Area of 3D Shapes
 */

// @lc code=start
// 1. 直接计算
// 2023-07-18 submission
// 90/90 cases passed
// Runtime: 4 ms, faster than 95.49% of cpp online submissions.
// Memory Usage: 9.2 MB, less than 69.42% of cpp online submissions.
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int top = 0, xz = 0, yz = 0;
        for (int i = 0; i < n; ++i) {
            int maxRow = 0, maxCol = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) ++top;
                maxRow = max(maxRow, grid[i][j]);
                maxCol = max(maxCol, grid[j][i]);
            }
            xz += maxRow;
            yz += maxCol;
        }
        return top + xz + yz;
    }
};
// @lc code=end
