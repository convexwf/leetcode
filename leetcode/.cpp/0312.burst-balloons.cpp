/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
// 1. 动态规划
// 2025-02-13 submission
// 73/73 cases passed
// Runtime: 106 ms, faster than 65.63% of cpp online submissions.
// Memory Usage: 13.9 MB, less than 56.77% of cpp online submissions.
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        vector<int> val(n + 2, 1);
        for (int i = 1; i <= n; ++i) {
            val[i] = nums[i - 1];
        }
        for (int len = 1; len <= n; ++len) {
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j],
                                   dp[i][k - 1] + dp[k + 1][j] + val[i - 1] * val[k] * val[j + 1]);
                }
            }
        }
        return dp[1][n];
    }
};
// @lc code=end
