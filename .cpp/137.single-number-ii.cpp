/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
// 1. 位操作
// 2022-07-23 submission
// 14/14 cases passed
// Runtime: 13 ms, faster than 55.33% of C++ online submissions.
// Memory Usage: 9.4 MB, less than 86.6% of C++ online submissions.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int idx = 0; idx < nums.size(); idx++) {
                sum += (nums[idx] >> i) & 1;
            }
            res += (sum % 3) << i; // |= or +=
        }
        return res;
    }
};
// @lc code=end
