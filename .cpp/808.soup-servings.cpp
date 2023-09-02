/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */

// @lc code=start
// 1. 记忆化搜索
// 2023-08-30 submission
// 43/43 cases passed
// Runtime: 3 ms, faster than 80.02% of cpp online submissions.
// Memory Usage: 15.4 MB, less than 53.86% of cpp online submissions.
class Solution {
public:
    double soupServings(int n) {
        if (n >= 5000) return 1.0;
        vector<vector<double>> memo(200, vector<double>(200, 0));
        return soupServings((n + 24) / 25, (n + 24) / 25, memo);
    }
    double soupServings(int a, int b, vector<vector<double>>& memo) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1;
        if (b <= 0) return 0;
        if (memo[a][b] > 0) return memo[a][b];
        memo[a][b] = 0.25 * (soupServings(a - 4, b, memo) + soupServings(a - 3, b - 1, memo) +
                             soupServings(a - 2, b - 2, memo) + soupServings(a - 1, b - 3, memo));
        return memo[a][b];
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划
// 2023-08-30 submission
// 43/43 cases passed
// Runtime: 2 ms, faster than 84.87% of cpp online submissions.
// Memory Usage:  MB, less than 84.82% of cpp online submissions.
class Solution {
public:
    double soupServings(int n) {
        if (n >= 5000) return 1;
        n = (n + 24) / 25;
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
        dp[0][0] = 0.5;
        for (int i = 1; i <= n; ++i) {
            dp[0][i] = 1;
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (dp[max(i - 4, 0)][j] + dp[max(i - 3, 0)][max(j - 1, 0)] +
                            dp[max(i - 2, 0)][max(j - 2, 0)] + dp[max(i - 1, 0)][max(j - 3, 0)]) /
                           4;
            }
        }
        return dp[n][n];
    }
};
// @lc code=end
