/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
// 1. 动态规划
// 2024-01-11 submission
// 65/65 cases passed
// Runtime: 231 ms, faster than 81.5% of cpp online submissions.
// Memory Usage:  MB, less than 77.93% of cpp online submissions.
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1001, 1));
        int res = 1;
        for (int i = 1; i < n; ++i) {
            for (int k = 0; k < i; ++k) {
                int j = nums[i] - nums[k] + 500;
                dp[i][j] = max(dp[i][j], dp[k][j] + 1);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end
