/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
// 2022-07-20 submission
// 41/41 cases passed
// Runtime: 13 ms, faster than 8.21% of C++ online submissions.
// Memory Usage: 7.6 MB, less than 90.54% of C++ online submissions.
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty() ||
            obstacleGrid[0][0] == 1) {
            return 0;
        }
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<long> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                }
                else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end