/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 */

// @lc code=start
// 1. 数学方法
// 2023-01-14 submission
// 71/71 cases passed
// Runtime: 3 ms, faster than 36.1% of cpp online submissions.
// Memory Usage: 6 MB, less than 72.2% of cpp online submissions.
class Solution {
public:
    int findNthDigit(int n) {
        long len = 1, cnt = 9, start = 1;
        while (n > len * cnt) {
            n -= len * cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }
        start += (n - 1) / len;
        string t = to_string(start);
        return t[(n - 1) % len] - '0';
    }
};
// @lc code=end
