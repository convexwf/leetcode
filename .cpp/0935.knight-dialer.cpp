/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 */

// @lc code=start
// 1. 动态规划
// 2024-01-12 submission
// 121/121 cases passed
// Runtime: 153 ms, faster than 32.77% of cpp online submissions.
// Memory Usage: 37.9 MB, less than 31.68% of cpp online submissions.
class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> jump = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {3, 9, 0},
                                    {},     {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
        const int mod = 1e9 + 7;

        vector<vector<int>> dp(n, vector<int>(10, 0));
        for (int j = 0; j < 10; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k : jump[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                }
            }
        }
        int res = 0;
        for (int j = 0; j < 10; ++j) {
            res = (res + dp[n - 1][j]) % mod;
        }
        return res;
    }
};
// @lc code=end
