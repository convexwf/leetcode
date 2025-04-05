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
        for (int i = 0; i < n; i++) {
            if (dp[i]) continue;
            for (int step = 1; i + step * step <= n; step++) {
                dp[i + step * step] = true;
            }
        }
        return dp[n];
    }
};
// @lc code=end

// @lc code=start
// Time Limit Exceeded
// 2. 记忆化搜索
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> memo(n + 1, -1);
        function<bool(int)> dfs = [&](int i) {
            if (i == 0) {
                return false;
            }
            if (memo[i] != -1) {
                return memo[i] == 1;
            }
            for (int step = 1; step * step <= i; ++step) {
                if (!dfs(i - step * step)) {
                    memo[i] = 1;
                    return true;
                }
            }
            memo[i] = 0;
            return false;
        };
        return dfs(n);
    }
};
// @lc code=end
