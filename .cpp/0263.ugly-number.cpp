/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
// 1. Brute Force
// 2022-08-26 submission
// 1013/1013 cases passed
// Runtime: 3 ms, faster than 58.82% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 69.21% of cpp online submissions.
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        return num == 1;
    }
};
// @lc code=end
