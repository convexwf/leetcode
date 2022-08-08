/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (41.16%)
 * Likes:    12888
 * Dislikes: 327
 * Total Accepted:    1.2M
 * Total Submissions: 3M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in non-decreasing order, find the
 * starting and ending position of a given target value.
 * 
 * If target is not found in the array, return [-1, -1].
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
// 2022-08-07 submission
// 88/88 cases passed
// Runtime: 3 ms, faster than 99.23% of C++ online submissions.
// Memory Usage: 13.7 MB, less than 63.47% of C++ online submissions.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() <= 0 || nums[0] > target || nums.back() < target)
            return {-1, -1};
        int start = firstGreaterEqual(nums, target);
        if (start >= nums.size() || nums[start] != target)
            return {-1, -1};
        int end = firstGreaterEqual(nums, target + 1) - 1;
        return {start, end};
    }

    int firstGreaterEqual(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
// @lc code=end