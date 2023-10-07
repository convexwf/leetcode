/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
// 2022-11-17 submission
// 150/150 cases passed
// Runtime: 4 ms, faster than 77.85% of C++ online submissions.
// Memory Usage: 10.1 MB, less than 71.41% of C++ online submissions.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        return nums[right];
    }
};
// @lc code=end

// @lc code=start
// 2022-11-17 submission
// 150/150 cases passed
// Runtime: 4 ms, faster than 77.85% of C++ online submissions.
// Memory Usage: 10.2 MB, less than 71.41% of C++ online submissions.
class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums, 0, (int)nums.size() - 1);
    }
    int helper(vector<int>& nums, int start, int end) {
        if (nums[start] <= nums[end]) return nums[start];
        int mid = (start + end) / 2;
        return min(helper(nums, start, mid), helper(nums, mid + 1, end));
    }
};
// @lc code=end