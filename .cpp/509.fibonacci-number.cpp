/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
// 2022-07-30 submission
// 31/31 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 78.78% of C++ online submissions.
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