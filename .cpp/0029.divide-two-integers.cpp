/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
// 1. 位操作
// 2020-07-04 submission
// 994/994 cases passed
// Runtime: 7 ms, faster than 32.77% of cpp online submissions.
// Memory Usage: 6 MB, less than 6.93% of cpp online submissions.
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long m = labs(dividend), n = labs(divisor), res = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if (n == 1) return sign == 1 ? m : -m;
        while (m >= n) {
            long t = n, p = 1;
            while (m >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        return sign == 1 ? res : -res;
    }
};
// @lc code=end

// @lc code=start
// 2. 位操作+递归
// 2023-01-14 submission
// 994/994 cases passed
// Runtime: 7 ms, faster than 32.77% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 49.63% of cpp online submissions.
class Solution {
public:
    int divide(int dividend, int divisor) {
        long m = labs(dividend), n = labs(divisor), res = 0;
        if (m < n) return 0;
        long t = n, p = 1;
        while (m > (t << 1)) {
            t <<= 1;
            p <<= 1;
        }
        res += p + divide(m - t, n);
        if ((dividend < 0) ^ (divisor < 0)) res = -res;
        return res > INT_MAX ? INT_MAX : res;
    }
};
// @lc code=end
