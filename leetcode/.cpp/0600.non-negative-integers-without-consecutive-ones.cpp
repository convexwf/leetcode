/*
 * @lc app=leetcode id=600 lang=cpp
 *
 * [600] Non-negative Integers without Consecutive Ones
 */

// @lc code=start
// 1. 数学方法-斐波那契数列+位操作
// 2025-02-24 submission
// 527/527 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.5 MB, less than 63.17% of cpp online submissions.
class Solution {
public:
    int findIntegers(int n) {
        vector<int> f(32);
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }

        int res = 0;
        int pre = 0;
        for (int i = 31; i >= 0; i--) {
            if ((n & (1 << i)) != 0) {
                res += f[i];
                if (pre == 1) {
                    return res;
                }
                pre = 1;
            }
            else {
                pre = 0;
            }
        }

        return res + 1;
    }
};
// @lc code=end
