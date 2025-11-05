/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

// @lc code=start
// 1. 计数
// 2021-12-22 submission
// 113/113 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.3 MB, less than 41.47% of cpp online submissions.
class Solution {
public:
    bool checkRecord(string s) {
        int acnt = 0, lcnt = 0;
        for (char c : s) {
            if (c == 'A') {
                ++acnt;
                lcnt = 0;
            }
            else if (c == 'L') {
                ++lcnt;
            }
            else {
                lcnt = 0;
            }
            if (acnt > 1 || lcnt > 2) return false;
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2. 正则匹配
// 2022-11-15 submission
// 113/113 cases passed
// Runtime: 8 ms, faster than 13.35% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 5.16% of cpp online submissions.
class Solution {
public:
    bool checkRecord(string s) {
        return !regex_search(s, regex("A.*A|LLL"));
    }
};
// @lc code=end
