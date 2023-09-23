/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
// 1. 动态规划
// 2023-09-19 submission
// 52/52 cases passed
// Runtime: 14 ms, faster than 65.29% of cpp online submissions.
// Memory Usage: 8.9 MB, less than 10.09% of cpp online submissions.
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int max_val = arr[i - 1];
            for (int j = 1; j <= k && i - j >= 0; ++j) {
                max_val = max(max_val, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j] + max_val * j);
            }
        }
        return dp[n];
    }
};
// @lc code=end
