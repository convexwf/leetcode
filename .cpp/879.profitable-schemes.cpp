/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

// @lc code=start
// 1. 动态规划+背包问题
// 2023-08-04 submission
// 45/45 cases passed
// Runtime: 235 ms, faster than 49.56% of cpp online submissions.
// Memory Usage: 53.8 MB, less than % of cpp online submissions.
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int mod = 1e9 + 7;
        int m = group.size();
        vector<vector<vector<int>>> dp(m + 1,
                                       vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            int members = group[i - 1];
            int earn = profit[i - 1];
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= minProfit; ++k) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= members) {
                        dp[i][j][k] =
                            (dp[i][j][k] + dp[i - 1][j - members][max(0, k - earn)]) % mod;
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i <= n; ++i) {
            sum = (sum + dp[m][i][minProfit]) % mod;
        }
        return sum;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划+背包问题+空间优化
// 2023-08-04 submission
// 45/45 cases passed
// Runtime: 86 ms, faster than 98.68% of cpp online submissions.
// Memory Usage:  MB, less than 96.93% of cpp online submissions.
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int mod = 1e9 + 7;
        int m = group.size();
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            int g = group[i - 1];
            int p = profit[i - 1];
            for (int j = n; j >= g; --j) {
                for (int k = minProfit; k >= 0; --k) {
                    dp[j][k] = (dp[j][k] + dp[j - g][max(0, k - p)]) % mod;
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= n; ++i) {
            res = (res + dp[i][minProfit]) % mod;
        }
        return res;
    }
};
// @lc code=end
