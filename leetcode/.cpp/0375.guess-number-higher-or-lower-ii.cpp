/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */

// @lc code=start
// 1. 动态规划
// 2023-06-16 submission
// 27/27 cases passed
// Runtime: 101 ms, faster than 78.75% of cpp online submissions.
// Memory Usage: 8.3 MB, less than 41.56% of cpp online submissions.
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 1; --i) {
            for (int j = i + 1; j <= n; ++j) {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
// @lc code=end

// @lc code=start
// 2. 递归+记忆化搜索
// 2023-06-16 submission
// 27/27 cases passed
// Runtime: 309 ms, faster than 31.62% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 79.01% of cpp online submissions.
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));
        return helper(1, n, memo);
    }
    int helper(int start, int end, vector<vector<int>>& memo) {
        if (start >= end) return 0;
        if (memo[start][end] != 0) return memo[start][end];
        int res = INT_MAX;
        for (int i = start; i <= end; ++i) {
            int tmp = i + max(helper(start, i - 1, memo), helper(i + 1, end, memo));
            res = min(res, tmp);
        }
        memo[start][end] = res;
        return res;
    }
};
// @lc code=end
