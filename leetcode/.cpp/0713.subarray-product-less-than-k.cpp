/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
// 1. 滑动窗口
// 2022-08-12 submission
// 97/97 cases passed
// Runtime: 141 ms, faster than 42.25% of cpp online submissions.
// Memory Usage: 61.1 MB, less than 93.31% of cpp online submissions.
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int res = 0, prod = 1, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            prod *= nums[right];
            while (left <= right && prod >= k) prod /= nums[left++];
            res += right - left + 1;
        }
        return res;
    }
};
// @lc code=end
