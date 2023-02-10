/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (18.39%)
 * Likes:    664
 * Dislikes: 1193
 * Total Accepted:    281.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '"0"'
 *
 * A valid number can be split up into these components (in order):
 *
 *
 * A decimal number or an integer.
 * (Optional) An 'e' or 'E', followed by an integer.
 *
 *
 * A decimal number can be split up into these components (in order):
 *
 *
 * (Optional) A sign character (either '+' or '-').
 * One of the following formats:
 *
 * One or more digits, followed by a dot '.'.
 * One or more digits, followed by a dot '.', followed by one or more
 * digits.
 * A dot '.', followed by one or more digits.
 *
 *
 *
 *
 * An integer can be split up into these components (in order):
 *
 *
 * (Optional) A sign character (either '+' or '-').
 * One or more digits.
 *
 *
 * For example, all the following are valid numbers: ["2", "0089", "-0.1",
 * "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93",
 * "-123.456e789"], while the following are not valid numbers: ["abc", "1a",
 * "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].
 *
 * Given a string s, return true if s is a valid number.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "0"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "e"
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: s = "."
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 20
 * s consists of only English letters (both uppercase and lowercase), digits
 * (0-9), plus '+', minus '-', or dot '.'.
 *
 *
 */

// @lc code=start
// 2020-07-14 submission
// 1490/1490 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.8 MB, less than 100% of C++ online submissions.
class Solution {
public:
    bool isNumber(string s) {
        int trans[][4] = {
            {2, -1, 1, 3}, // 0
            {2, -1, -1, 3},// 1
            {2, 5, -1, 4}, // 2
            {4, -1, -1, -1},// 3
            {4, 5, -1, -1},// 4
            {7, -1, 6, -1},// 5
            {7, -1, -1, -1},// 6
            {7, -1, -1, -1},//7
            {-1, -1, -1, -1}};//8
        int accepted[] = {2, 4, 7};

        s.append(1, ' ');
        int cur = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (cur == 0 || cur == 8) continue;
                else if (cur == 2 || cur ==4 || cur == 7) cur = 8;
                else cur = -1;;
            }
            else if (s[i] >= '0' && s[i] <= '9') cur = trans[cur][0];
            else if (s[i] == 'e' || s[i] == 'E') cur = trans[cur][1];
            else if (s[i] == '+' || s[i] == '-') cur = trans[cur][2];
            else if (s[i] == '.') cur = trans[cur][3];
            else cur = -1;
            if (cur == -1) return false;
        }
        return cur == 8;
    }
};
// @lc code=end
