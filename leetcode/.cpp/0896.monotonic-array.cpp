/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */

// @lc code=start
// 1. 模拟
// 2023-09-27 submission
// 371/371 cases passed
// Runtime: 128 ms, faster than 38.33% of cpp online submissions.
// Memory Usage: 96.9 MB, less than 13.16% of cpp online submissions.
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true, dec = true;
        for (int i = 1; i < nums.size(); ++i) {
            inc &= nums[i - 1] <= nums[i];
            dec &= nums[i - 1] >= nums[i];
            if (!inc && !dec) return false;
        }
        return true;
    }
};
// @lc code=end
