/*
 * @lc app=leetcode id=807 lang=cpp
 *
 * [807] Max Increase to Keep City Skyline
 */

// @lc code=start
// 1. 遍历
// 2023-12-13 submission
// 133/133 cases passed
// Runtime: 5 ms, faster than 66.48% of cpp online submissions.
// Memory Usage: 10.5 MB, less than 35.71% of cpp online submissions.
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row_max(n, 0), col_max(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                row_max[i] = max(row_max[i], grid[i][j]);
                col_max[j] = max(col_max[j], grid[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res += min(row_max[i], col_max[j]) - grid[i][j];
            }
        }
        return res;
    }
};
// @lc code=end
