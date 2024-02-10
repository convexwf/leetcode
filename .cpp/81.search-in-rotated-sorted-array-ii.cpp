/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
// 2022-11-17 submission
// 280/280 cases passed
// Runtime: 11 ms, faster than 69.82% of C++ online submissions.
// Memory Usage: 13.9 MB, less than 92.22% of C++ online submissions.
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else if (nums[mid] > nums[right]){
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            } else --right;
        }
        return false;
    }
};
// @lc code=end