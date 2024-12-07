/*
 * @lc app=leetcode id=568 lang=cpp
 *
 * [568] Maximum Vacation Days
 */

// @lc code=start
// 1. 动态规划
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size();
        vector<vector<int>> dp(k, vector<int>(n, -1));
        dp[0][0] = 0;
        for (int i = 1; i < n; ++i) {
            if (flights[0][i] == 1) {
                dp[0][i] = days[i][0];
            }
        }
        for (int i = 1; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int l = 0; l < n; ++l) {
                    if (dp[i - 1][l] != -1 && (flights[l][j] == 1 || l == j)) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][l] + days[j][i]);
                    }
                }
            }
        }
        return *max_element(dp[k - 1].begin(), dp[k - 1].end());
    }
};
// @lc code=end
