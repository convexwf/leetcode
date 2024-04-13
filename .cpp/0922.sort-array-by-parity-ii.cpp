/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */

// @lc code=start
// 1. 双指针
// 2024-01-09 submission
// 61/61 cases passed
// Runtime: 17 ms, faster than 52.54% of cpp online submissions.
// Memory Usage: 21.7 MB, less than 72.17% of cpp online submissions.
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd = 1, even = 0;
        while (odd < nums.size() && even < nums.size()) {
            while (odd < nums.size() && nums[odd] % 2 == 1) odd += 2;
            while (even < nums.size() && nums[even] % 2 == 0) even += 2;
            if (odd < nums.size() && even < nums.size()) swap(nums[odd], nums[even]);
        }
        return nums;
    }
};
// @lc code=end
