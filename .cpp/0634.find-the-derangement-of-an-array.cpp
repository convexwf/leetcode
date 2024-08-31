/*
 * @lc app=leetcode id=634 lang=cpp
 *
 * [634] Find the Derangement of An Array
 */

// @lc code=start
// 1. 动态规划
class Solution {
public:
    int findDerangement(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        vector<long long> dp(n + 1, 0);
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % 1000000007;
        }
        return dp[n];
    }
};
// @lc code=end
