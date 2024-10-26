/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
// 1. 动态规划
// 2023-02-13 submission
// 141/141 cases passed
// Runtime: 142 ms, faster than 87.8% of cpp online submissions.
// Memory Usage: 9.8 MB, less than 89.85% of cpp online submissions.
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
        if (sum & 1) return false;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};
// @lc code=end

// @lc code=start
// 2. 位操作
// 2023-02-13 submission
// 141/141 cases passed
// Runtime: 16 ms, faster than 99.09% of cpp online submissions.
// Memory Usage: 9.7 MB, less than 94.94% of cpp online submissions.
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int num : nums) {
            bits |= (bits << num);
        }
        return (sum % 2 == 0) && bits[sum >> 1];
    }
};
// @lc code=end
