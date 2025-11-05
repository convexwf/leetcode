/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
// 1. 动态规划
// 2025-04-06 submission
// 32/32 cases passed
// Runtime: 4 ms, faster than 73.09% of cpp online submissions.
// Memory Usage: 30.3 MB, less than 43.94% of cpp online submissions.
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) continue;
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end
