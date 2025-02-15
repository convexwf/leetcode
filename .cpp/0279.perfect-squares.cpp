/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
// 1. 动态规划
// 2025-02-14 submission
// 589/589 cases passed
// Runtime: 46 ms, faster than 60.63% of cpp online submissions.
// Memory Usage: 13.2 MB, less than 67.91% of cpp online submissions.
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end
