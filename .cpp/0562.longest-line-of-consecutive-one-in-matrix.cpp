/*
 * @lc app=leetcode id=562 lang=cpp
 *
 * [562] Longest Line of Consecutive One in Matrix
 */

// @lc code=start
// 1. 动态规划
class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, 0)));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    for (int k = 0; k < 4; ++k) {
                        dp[i][j][k] = 1;
                    }
                    if (j > 0) dp[i][j][0] += dp[i][j - 1][0];
                    if (i > 0) dp[i][j][1] += dp[i - 1][j][1];
                    if (i > 0 && j > 0) dp[i][j][2] += dp[i - 1][j - 1][2];
                    if (i > 0 && j < n - 1) dp[i][j][3] += dp[i - 1][j + 1][3];
                    res = max(res, max(dp[i][j][0], max(dp[i][j][1], max(dp[i][j][2], dp[i][j][3])));
                }
            }
        }
        return res;
    }
};
// @lc code=end
