/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
// 2022-07-28 submission
// 61/61 cases passed
// Runtime: 15 ms, faster than 53.74% of C++ online submissions.
// Memory Usage: 9.6 MB, less than 90.08% of C++ online submissions.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) dp[j] += grid[i][j];
                else dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
            }
        }
        return dp.back();
    }
};
// @lc code=end