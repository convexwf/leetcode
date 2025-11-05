/*
 * @lc app=leetcode id=892 lang=cpp
 *
 * [892] Surface Area of 3D Shapes
 */

// @lc code=start
// 1. 遍历
// 2023-10-18 submission
// 90/90 cases passed
// Runtime: 5 ms, faster than 73.1% of cpp online submissions.
// Memory Usage: 9.7 MB, less than 28.48% of cpp online submissions.
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    ans += grid[i][j] * 4 + 2;
                    if (i > 0) ans -= min(grid[i][j], grid[i - 1][j]) * 2;
                    if (j > 0) ans -= min(grid[i][j], grid[i][j - 1]) * 2;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
