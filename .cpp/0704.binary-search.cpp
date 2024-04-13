/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
// 1. 二分查找，左边界为 0，右边界为数组长度减一
// 2023-11-27 submission
// 47/47 cases passed
// Runtime: 26 ms, faster than 76.13% of cpp online submissions.
// Memory Usage: 27.8 MB, less than 92.18% of cpp online submissions.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

// @lc code=start
// 2. 二分查找，左边界为 0，右边界为数组长度
// 2023-11-27 submission
// 47/47 cases passed
// Runtime: 22 ms, faster than 92.94% of cpp online submissions.
// Memory Usage: 27.8 MB, less than 54.51% of cpp online submissions.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return -1;
    }
};
// @lc code=end
