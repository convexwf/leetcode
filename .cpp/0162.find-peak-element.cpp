/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
// 1. 二分查找
// 2020-11-11 submission
// 65/65 cases passed
// Runtime: 4 ms, faster than 81.83% of cpp online submissions.
// Memory Usage: 8.8 MB, less than 75.54% of cpp online submissions.
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end
