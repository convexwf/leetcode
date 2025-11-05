/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
// 1. 动态规划
// 2025-02-14 submission
// 16/16 cases passed
// Runtime: 4 ms, faster than 30.27% of cpp online submissions.
// Memory Usage:  MB, less than 86.94% of cpp online submissions.
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end
