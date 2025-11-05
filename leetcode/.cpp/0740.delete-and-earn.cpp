/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
// 1. 动态规划
// 2023-12-14 submission
// 51/51 cases passed
// Runtime: 3 ms, faster than 98.63% of cpp online submissions.
// Memory Usage:  MB, less than 89.29% of cpp online submissions.
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = 0;
        for (int val : nums) {
            maxVal = max(maxVal, val);
        }
        vector<int> sum(maxVal + 1);
        for (int val : nums) {
            sum[val] += val;
        }
        return rob(sum);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[nums.size()];
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划优化
// 2023-12-14 submission
// 51/51 cases passed
// Runtime: 13 ms, faster than 48.44% of cpp online submissions.
// Memory Usage: 14.5 MB, less than 32.71% of cpp online submissions.
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> sums(10001, 0);
        for (int num : nums) sums[num] += num;
        for (int i = 2; i < 10001; ++i) {
            sums[i] = max(sums[i - 1], sums[i - 2] + sums[i]);
        }
        return sums[10000];
    }
};
// @lc code=end
