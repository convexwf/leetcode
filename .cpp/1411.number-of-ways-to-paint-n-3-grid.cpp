/*
 * @lc app=leetcode id=1411 lang=cpp
 *
 * [1411] Number of Ways to Paint N × 3 Grid
 */

// @lc code=start
// 1. 数学方法
// 2024-03-06 submission
// 50/50 cases passed
// Runtime: 2 ms, faster than 72.84% of cpp online submissions.
// Memory Usage:  MB, less than 74.57% of cpp online submissions.
class Solution {
public:
    int numOfWays(int n) {
        long long f0 = 6, f1 = 6, mod = 1e9 + 7;
        for (int i = 1; i < n; i++) {
            long long t0 = f0, t1 = f1;
            f0 = (3 * t0 + 2 * t1) % mod;
            f1 = (2 * t0 + 2 * t1) % mod;
        }
        return (f0 + f1) % mod;
    }
};
// @lc code=end
