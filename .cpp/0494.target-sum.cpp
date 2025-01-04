/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
// 1. 动态规划
// 2024-12-30 submission
// 140/140 cases passed
// Runtime: 4 ms, faster than 83.48% of cpp online submissions.
// Memory Usage: 15.6 MB, less than 41.21% of cpp online submissions.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) % 2 != 0 || sum < target || (sum + target) < 0) {
            return 0;
        }
        int target_sum = (sum + target) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target_sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target_sum; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][target_sum];
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划-空间优化
// 2024-12-30 submission
// 140/140 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 12.4 MB, less than 54.51% of cpp online submissions.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) % 2 != 0 || sum < target || (sum + target) < 0) {
            return 0;
        }
        int target_sum = (sum + target) / 2;
        int n = nums.size();
        vector<int> dp(target_sum + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = target_sum; j >= nums[i - 1]; --j) {
                dp[j] += dp[j - nums[i - 1]];
            }
        }
        return dp[target_sum];
    }
};
// @lc code=end
