/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
// 1. 动态规划
// 2023-10-20 submission
// 111/111 cases passed
// Runtime: 48 ms, faster than 65.47% of cpp online submissions.
// Memory Usage: 40.1 MB, less than 41.12% of cpp online submissions.
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], minSum = nums[0];
        int curMax = 0, curMin = 0;
        int total = 0;
        for (int num : nums) {
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
            total += num;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};
// @lc code=end
