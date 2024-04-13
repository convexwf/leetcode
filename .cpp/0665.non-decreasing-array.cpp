/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

// @lc code=start
// 1. brute force
// 2023-08-29 submission
// 335/335 cases passed
// Runtime: 18 ms, faster than 85.04% of cpp online submissions.
// Memory Usage:  MB, less than 74.04% of cpp online submissions.
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                if (--cnt < 0) return false;
                if (i > 0 && nums[i - 1] > nums[i + 1]) {
                    nums[i + 1] = nums[i];
                }
                else {
                    nums[i] = nums[i + 1];
                }
            }
        }
        return true;
    }
};
// @lc code=end
