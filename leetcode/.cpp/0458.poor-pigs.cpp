/*
 * @lc app=leetcode id=458 lang=cpp
 *
 * [458] Poor Pigs
 */

// @lc code=start
// 1. 位运算
// 2023-11-15 submission
// 26/26 cases passed
// Runtime: 2 ms, faster than 57.14% of cpp online submissions.
// Memory Usage: 6.3 MB, less than 82.89% of cpp online submissions.
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = minutesToTest / minutesToDie + 1;
        int n = 0, pow = 1;
        while (pow < buckets) {
            pow *= base;
            ++n;
        }
        return n;
    }
};
// @lc code=end
