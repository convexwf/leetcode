/*
 * @lc app=leetcode id=1510 lang=cpp
 *
 * [1510] Stone Game IV
 */

// @lc code=start
// 1. 动态规划
// 2020-10-26 submission
// 72/72 cases passed
// Runtime: 9 ms, faster than 98.51% of cpp online submissions.
// Memory Usage: 6.3 MB, less than 79.76% of cpp online submissions.
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 0; i < n ; i++) {
            if (dp[i]) continue;
            for (int step = 1; i + step * step <= n; step++) {
                dp[i + step * step] = true;
            }
        }
        return dp[n];
    }
};
// @lc code=end

