/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
// 2022-08-27 submission
// 1108/1108 cases passed
// Runtime: 3 ms, faster than 59.97% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 26.88% of C++ online submissions.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (!(n & (n - 1)));
    }
};
// @lc code=end
