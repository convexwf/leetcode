/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 *
 * https://leetcode.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (47.06%)
 * Likes:    209
 * Dislikes: 13
 * Total Accepted:    130K
 * Total Submissions: 275.9K
 * Testcase Example:  '"PPALLP"'
 *
 * You are given a string s representing an attendance record for a student
 * where each character signifies whether the student was absent, late, or
 * present on that day. The record only contains the following three
 * characters:
 * 
 * 
 * 'A': Absent.
 * 'L': Late.
 * 'P': Present.
 * 
 * 
 * The student is eligible for an attendance award if they meet both of the
 * following criteria:
 * 
 * 
 * The student was absent ('A') for strictly fewer than 2 days total.
 * The student was never late ('L') for 3 or more consecutive days.
 * 
 * 
 * Return true if the student is eligible for an attendance award, or false
 * otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PPALLP"
 * Output: true
 * Explanation: The student has fewer than 2 absences and was never late 3 or
 * more consecutive days.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PPALLL"
 * Output: false
 * Explanation: The student was late 3 consecutive days in the last 3 days, so
 * is not eligible for the award.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s[i] is either 'A', 'L', or 'P'.
 * 
 * 
 */

// @lc code=start
// 2021-12-22 submission
// 113/113 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.3 MB, less than 41.47% of C++ online submissions.
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
            if (acnt >= 2 || lcnt >= 3) 
                return false;
        }
        return true;
    }
};
// @lc code=end

