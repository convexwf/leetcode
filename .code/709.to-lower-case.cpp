/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 */

// @lc code=start
// 2021-12-16 submission
// 114/114 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.2 MB, less than 51.19% of C++ online submissions.
class Solution {
public:
    string toLowerCase(string s) {
        string res;
        for (char c : s) {
            if ('A' <= c && c <= 'Z') res.append(1, c + ('a' - 'A'));
            else res.append(1, c);
        }
        return res;
    }
};
// @lc code=end
