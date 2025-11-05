/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
// 1. 位操作
// 2023-05-18 submission
// 100/100 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 64.34% of cpp online submissions.
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string hex = "0123456789abcdef";
        string ans = "";
        unsigned int n = num;
        while (n) {
            ans = hex[n & 0xf] + ans;
            n >>= 4;
        }
        return ans;
    }
};
// @lc code=end
