/*
 * @lc app=leetcode id=956 lang=cpp
 *
 * [956] Tallest Billboard
 */

// @lc code=start
// 1. 动态规划
// 2025-06-04 submission
// 80/80 cases passed
// Runtime: 34 ms, faster than 77.94% of cpp online submissions.
// Memory Usage: 30.8 MB, less than 60.9% of cpp online submissions.
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = accumulate(rods.begin(), rods.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

        for (int i = 0; i <= sum; ++i) {
            dp[0][i] = INT_MIN; // Initialize to a very small value
        }
        dp[0][0] = 0;

        for (int i = 1; i <= n; ++i) {
            int rod = rods[i - 1];
            for (int j = 0; j <= sum; ++j) {
                dp[i][j] = dp[i - 1][j]; // default case: not using the current rod
                if (j - rod >= 0) {
                    // case 1 : add to right side
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - rod] + rod);
                }
                else {
                    // case 2 : add to left side, if left side is still less than or equal to right
                    // side
                    dp[i][j] = max(dp[i][j], dp[i - 1][rod - j] + j); // add to left side
                }
                if (j + rod <= sum) {
                    // case 3 : add to left side, if left side becomes greater than right side
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + rod]);
                }
            }
        }
        return dp[n][0];
    }
};
// @lc code=end
