/*
 * @lc app=leetcode id=1060 lang=cpp
 *
 * [1060] Missing Element in Sorted Array
 */

// @lc code=start
// 1. 二分查找
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        auto missing = [&](int idx) { return nums[idx] - nums[0] - idx; };
        if (missing(n - 1) < k) {
            return nums[n - 1] + k - missing(n - 1);
        }
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (missing(mid) >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return nums[left - 1] + k - missing(left - 1);
    }
};
// @lc code=end
