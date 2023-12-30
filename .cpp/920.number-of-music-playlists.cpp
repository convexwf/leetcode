/*
 * @lc app=leetcode id=920 lang=cpp
 *
 * [920] Number of Music Playlists
 */

// @lc code=start
// 1. 动态规划
// 2023-12-25 submission
// 83/83 cases passed
// Runtime: 6 ms, faster than 29.63% of cpp online submissions.
// Memory Usage: 9.5 MB, less than 29.06% of cpp online submissions.
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long>> dp(goal + 1, vector<long>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) + dp[i - 1][j] * max(j - k, 0);
                dp[i][j] %= 1000000007;
            }
        }
        return dp[goal][n];
    }
};
// @lc code=end
