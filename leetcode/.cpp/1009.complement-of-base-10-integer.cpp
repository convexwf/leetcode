/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
// 1. 位操作
// 2023-10-25 submission
// 128/128 cases passed
// Runtime: 2 ms, faster than 47.54% of cpp online submissions.
// Memory Usage: 6.4 MB, less than 24.42% of cpp online submissions.
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        uint32_t mask = INT_MAX;
        while (mask & n) mask <<= 1;
        return ~mask & ~n;
    }
};
// @lc code=end
