/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
// 1. 递归
// 2024-08-08 submission
// 31/31 cases passed
// Runtime: 15 ms, faster than 15.6% of cpp online submissions.
// Memory Usage: 7.2 MB, less than 48.39% of cpp online submissions.
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fib(n - 1) + fib(n - 2);
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划
// 2022-07-30 submission
// 31/31 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 78.78% of cpp online submissions.
class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1;
        while (n-- > 0) {
            b += a;
            a = b - a;
        }
        return a;
    }
};
// @lc code=end
