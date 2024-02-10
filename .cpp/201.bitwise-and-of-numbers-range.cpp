/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
// 2022-11-14 submission
// 8268/8268 cases passed
// Runtime: 24 ms, faster than 44.81% of C++ online submissions.
// Memory Usage: 6 MB, less than 32.15% of C++ online submissions.
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