/*
 * @lc app=leetcode id=1017 lang=cpp
 *
 * [1017] Convert to Base -2
 */

// @lc code=start
// 1. 模拟
// 2023-07-20 submission
// 170/170 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.1 MB, less than 38.61% of cpp online submissions.
class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) return "0";
        string res;
        while (N != 0) {
            int remainder = N % -2;
            N /= -2;
            if (remainder < 0) {
                remainder += 2;
                N += 1;
            }
            res = to_string(remainder) + res;
        }
        return res;
    }
};
// @lc code=end
