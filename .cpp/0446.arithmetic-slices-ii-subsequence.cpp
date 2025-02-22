/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
// 1. 动态规划+哈希表
// 2025-02-21 submission
// 101/101 cases passed
// Runtime: 967 ms, faster than 28.22% of cpp online submissions.
// Memory Usage: 289.3 MB, less than 10.92% of cpp online submissions.
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long ans = 0;
        vector<unordered_map<long, int>> dp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long diff = (long)nums[i] - nums[j];
                dp[i][diff] += dp[j][diff] + 1;
                ans += dp[j][diff];
            }
        }
        return ans;
    }
};
// @lc code=end
