/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
// 1. 位操作
// 2022-11-14 submission
// 26/26 cases passed
// Runtime: 2 ms, faster than 43.81% of cpp online submissions.
// Memory Usage: 5.8 MB, less than 73.12% of cpp online submissions.
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
// @lc code=end
