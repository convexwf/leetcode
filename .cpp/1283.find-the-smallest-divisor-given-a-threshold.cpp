/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */

// @lc code=start
// 1. 二分查找
// 2020-11-07 submission
// 71/71 cases passed
// Runtime: 4 ms, faster than 88.87% of cpp online submissions.
// Memory Usage: 26.1 MB, less than 81.66% of cpp online submissions.
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            int sum = 0;
            for (int num : nums) {
                sum += (num + mid - 1) / mid; // ceil(num / mid)
            }
            if (sum > threshold) {
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
