/*
 * @lc app=leetcode id=1066 lang=cpp
 *
 * [1066] Campus Bikes II
 */

// @lc code=start
// 1. 动态规划
class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<vector<int>> dp(n + 1, vector<int>(1 << m, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 1 << m; ++j) {
                for (int k = 0; k < m; ++k) {
                    if (j >> k & 1) {
                        int d = abs(workers[i - 1][0] - bikes[k][0]) +
                                abs(workers[i - 1][1] - bikes[k][1]);
                        dp[i][j] = min(dp[i][j], dp[i - 1][j ^ (1 << k)] + d);
                    }
                }
            }
        }
        return *min_element(dp[n], dp[n] + (1 << m));
    }
};
// @lc code=end
