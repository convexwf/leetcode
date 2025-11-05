/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
// 1. 动态规划
// 2023-07-05 submission
// 39/39 cases passed
// Runtime: 4 ms, faster than 36.84% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 23.11% of cpp online submissions.
class Solution {
public:
    int numTilings(int n) {
        if (n == 1 || n == 2) return n;
        vector<long> dp(n + 1, 0);
        vector<long> sum(n + 1, 0);
        const int mod = 1000000007;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        sum[0] = 1;
        sum[1] = 2;
        sum[2] = 4;
        for (int i = 3; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2] + 2 * sum[i - 3]) % mod;
            sum[i] = (sum[i - 1] + dp[i]) % mod;
        }
        return dp[n];
    }
};
// @lc code=end
