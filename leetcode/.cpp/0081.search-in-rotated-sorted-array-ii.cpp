/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
// 1. 二分查找
// 2022-11-17 submission
// 280/280 cases passed
// Runtime: 11 ms, faster than 69.82% of cpp online submissions.
// Memory Usage: 13.9 MB, less than 92.22% of cpp online submissions.
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] == nums[right]) {
                right--;
            }
            else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};
// @lc code=end
