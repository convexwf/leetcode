/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
// 2022-11-14 submission
// 26/26 cases passed
// Runtime: 2 ms, faster than 43.81% of C++ online submissions.
// Memory Usage: 5.8 MB, less than 73.12% of C++ online submissions.
class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b & 0x7fffffff) << 1);
    }
};
// @lc code=end