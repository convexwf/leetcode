/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
// 2022-11-14 submission
// 18/18 cases passed
// Runtime: 3 ms, faster than 35.72% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 47.17% of C++ online submissions.
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            res = string(1, --n % 26 + 'A') + res;
            n /= 26;
        }
        return res;
    }
};
// @lc code=end