/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 */

// @lc code=start
// 2019-09-15 submission
// 60/60 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 62.65% of C++ online submissions.
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
// @lc code=end
