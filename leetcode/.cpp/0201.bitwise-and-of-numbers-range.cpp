/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
// 1. 位操作-同时逻辑右移
// 2022-11-14 submission
// 8268/8268 cases passed
// Runtime: 24 ms, faster than 44.81% of cpp online submissions.
// Memory Usage: 6 MB, less than 32.15% of cpp online submissions.
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return (m << i);
    }
};
// @lc code=end

// @lc code=start
// 2. 位操作-去除最右边的 1
// 2024-04-16 submission
// 8270/8270 cases passed
// Runtime: 8 ms, faster than 49.38% of cpp online submissions.
// Memory Usage: 8.9 MB, less than 8.5% of cpp online submissions.
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right &= (right - 1);
        }
        return right;
    }
};
// @lc code=end
