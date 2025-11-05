/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
// 1. 二分查找
// 2022-11-17 submission
// 64/64 cases passed
// Runtime: 11 ms, faster than 47.12% of cpp online submissions.
// Memory Usage: 9.8 MB, less than 22.94% of cpp online submissions.
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.back() < target) return nums.size();
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return right;
    }
};
// @lc code=end
