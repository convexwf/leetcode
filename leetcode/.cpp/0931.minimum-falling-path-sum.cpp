/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
// 1. 动态规划
// 2023-09-22 submission
// 50/50 cases passed
// Runtime: 13 ms, faster than 51.42% of cpp online submissions.
// Memory Usage: 10.9 MB, less than 9.25% of cpp online submissions.
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j - 1 >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
                if (j + 1 < n) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][j]) + matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; ++j) {
            ans = min(ans, dp[n - 1][j]);
        }
        return ans;
    }
};
// @lc code=end
