/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
// 1. 动态规划
// 2022-07-27 submission
// 45/45 cases passed
// Runtime: 4 ms, faster than 22.52% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 83.64% of cpp online submissions.
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        for (int i = 0; i < n - 1; i++) {
            b += a;
            a = b - a;
        }
        return b;
    }
};
// @lc code=end
