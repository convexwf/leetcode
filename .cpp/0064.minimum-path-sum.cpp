/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
// 1. 动态规划
// 2024-06-22 submission
// 65/65 cases passed
// Runtime: 10 ms, faster than 26.38% of cpp online submissions.
// Memory Usage: 12.6 MB, less than 36.19% of cpp online submissions.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[1][1] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划+空间优化
// 2022-07-28 submission
// 61/61 cases passed
// Runtime: 15 ms, faster than 53.74% of cpp online submissions.
// Memory Usage: 9.6 MB, less than 90.08% of cpp online submissions.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < m; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
            }
        }
        return dp[n-1];
    }
};
// @lc code=end
