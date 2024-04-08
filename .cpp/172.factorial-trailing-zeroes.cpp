/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
// 1. 数学方法
// 2023-01-14 submission
// 500/500 cases passed
// Runtime: 5 ms, faster than 26.38% of cpp online submissions.
// Memory Usage: 6 MB, less than 8.85% of cpp online submissions.
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 数学方法+递归
// 2023-01-14 submission
// 500/500 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6 MB, less than 53.88% of cpp online submissions.
class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
// @lc code=end
