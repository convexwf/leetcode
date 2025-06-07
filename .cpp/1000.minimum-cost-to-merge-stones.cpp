/*
 * @lc app=leetcode id=1000 lang=cpp
 *
 * [1000] Minimum Cost to Merge Stones
 */

// @lc code=start
// 1. 前缀和+动态规划
// 2025-06-05 submission
// 84/84 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 11.4 MB, less than 32.29% of cpp online submissions.
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> prefixSum(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stones[i];
        }

        for (int len = k; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int m = i; m < j; m += k - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
                }
                if ((j - i) % (k - 1) == 0) {
                    dp[i][j] += prefixSum[j + 1] - prefixSum[i];
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end
