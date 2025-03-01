/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
// 1. 动态规划
// 2022-11-17 submission
// 54/54 cases passed
// Runtime: 714 ms, faster than 30.77% of cpp online submissions.
// Memory Usage: 10.6 MB, less than 50.47% of cpp online submissions.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 贪心算法+二分查找
// 2022-11-18 submission
// 54/54 cases passed
// Runtime: 9 ms, faster than 96.56% of cpp online submissions.
// Memory Usage: 10.4 MB, less than 72.3% of cpp online submissions.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if (it == dp.end()) {
                dp.push_back(nums[i]);
            }
            else {
                *it = nums[i];
            }
        }
        return dp.size();
    }
};
// @lc code=end
