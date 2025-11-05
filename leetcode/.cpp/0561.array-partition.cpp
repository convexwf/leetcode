/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition
 */

// @lc code=start
// 1. 排序
// 2024-11-06 submission
// 85/85 cases passed
// Runtime: 12 ms, faster than 54.06% of cpp online submissions.
// Memory Usage: 32.1 MB, less than 65.64% of cpp online submissions.
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};
// @lc code=end
