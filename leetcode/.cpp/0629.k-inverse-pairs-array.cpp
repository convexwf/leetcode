/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 */

// @lc code=start
// 1. 动态规划
// 2025-02-27 submission
// 81/81 cases passed
// Runtime: 23 ms, faster than 69.95% of cpp online submissions.
// Memory Usage:  MB, less than 19.71% of cpp online submissions.
class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
                if (j >= i) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod) % mod;
                }
            }
        }
        return dp[n][k];
    }
};
// @lc code=end
