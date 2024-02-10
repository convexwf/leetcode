/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
// 1. 两次遍历
// 2022-08-01 submission
// 265/265 cases passed
// Runtime: 3 ms, faster than 90.13% of C++ online submissions.
// Memory Usage: 12.1 MB, less than 36.5% of C++ online submissions.
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2, j = n - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            while (nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end
