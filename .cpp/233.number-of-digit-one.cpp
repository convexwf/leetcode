/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 */

// @lc code=start
// 2023-02-02 submission
// 38/38 cases passed
// Runtime: 3 ms, faster than 41.94% of C++ online submissions.
// Memory Usage: 5.8 MB, less than 94.5% of C++ online submissions.
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        long a = 1, b = 1; // n=1000000000 int 会溢出
        while (n > 0) {
            res += (n + 8) / 10 * a + (n % 10 == 1) * b;
            b += n % 10 * a;
            a *= 10;
            n /= 10;
        }
        return res;
    }
};
// @lc code=end