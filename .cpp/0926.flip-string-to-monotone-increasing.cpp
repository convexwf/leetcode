/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */

// @lc code=start
// 1. 字符串遍历
// 2023-07-13 submission
// 93/93 cases passed
// Runtime: 23 ms, faster than 84.1% of cpp online submissions.
// Memory Usage:  MB, less than 72.39% of cpp online submissions.
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zeros = 0, ones = 0;
        for (char c : s) {
            if (c == '0')
                zeros++;
            else
                ones++;
        }
        int leftOnes = 0, rightZeros = zeros;
        int res = zeros;
        for (char c : s) {
            if (c == '0')
                rightZeros--;
            else
                leftOnes++;
            res = min(res, leftOnes + rightZeros);
        }
        return res;
    }
};
// @lc code=end
