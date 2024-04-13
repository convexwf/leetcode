/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
// 2022-08-07 submission
// 88/88 cases passed
// Runtime: 3 ms, faster than 99.23% of cpp online submissions.
// Memory Usage: 13.7 MB, less than 63.47% of cpp online submissions.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() <= 0 || nums[0] > target || nums.back() < target) return {-1, -1};
        int start = firstGreaterEqual(nums, target);
        if (start >= nums.size() || nums[start] != target) return {-1, -1};
        int end = firstGreaterEqual(nums, target + 1) - 1;
        return {start, end};
    }

    int firstGreaterEqual(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }
};
// @lc code=end
