/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 */

// @lc code=start
// 1. 数学方法-快速幂
// 2024-07-26 submission
// 57/57 cases passed
// Runtime: 8 ms, faster than 44.09% of cpp online submissions.
// Memory Usage:  MB, less than 55.32% of cpp online submissions.
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int i = 0; i < b.size(); ++i) {
            res = (pow(res, 10) % 1337) * (pow(a, b[i]) % 1337) % 1337;
        }
        return res;
    }

    int pow(int a, int b) {
        if (b == 0) return 1;
        a %= 1337;
        int res = 1;
        for (int i = 0; i < b; ++i) {
            res = (res * a) % 1337;
        }
        return res;
    }
};
// @lc code=end
