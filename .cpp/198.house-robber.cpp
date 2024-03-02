/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
// 1. 动态规划(当前位置必须要抢)
// 2022-08-26 submission
// 68/68 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 7.6 MB, less than 77.09% of C++ online submissions.
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> maxSum;
        if (nums.size() >= 1) maxSum.push_back(nums[0]);
        if (nums.size() >= 2) maxSum.push_back(nums[1]);
        if (nums.size() >= 3) maxSum.push_back(nums[0] + nums[2]);
        for (int i = 3; i < nums.size(); i++) {
            auto temp = maxSum[i - 2] > maxSum[i - 3] ? maxSum[i - 2] : maxSum[i - 3];
            maxSum.push_back(temp + nums[i]);
        }
        return *max_element(maxSum.begin(), maxSum.end());
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划(当前位置不一定要抢)
// 2022-08-26 submission
// 68/68 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 7.7 MB, less than 77.09% of C++ online submissions.
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp = {nums[0], max(nums[0], nums[1])};
        for (int i = 2; i < nums.size(); ++i) {
            dp.push_back(max(nums[i] + dp[i - 2], dp[i - 1]));
        }
        return dp.back();
    }
};
// @lc code=end
