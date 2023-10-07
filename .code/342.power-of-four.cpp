/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
// 2022-11-14 submission
// 1061/1061 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 26.13% of C++ online submissions.
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && !(n & (n - 1)) && (n - 1) % 3 == 0;
    }
};
// @lc code=end