/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (47.81%)
 * Likes:    518
 * Dislikes: 195
 * Total Accepted:    91.6K
 * Total Submissions: 191.6K
 * Testcase Example:  '100'
 *
 * Given an integer num, return a string of its base 7 representation.
 *
 *
 * Example 1:
 * Input: num = 100
 * Output: "202"
 * Example 2:
 * Input: num = -7
 * Output: "-10"
 *
 *
 * Constraints:
 *
 *
 * -10^7 <= num <= 10^7
 *
 *
 */

// @lc code=start
// 2022-08-26 submission
// 241/241 cases passed
// Runtime: 3 ms, faster than 40.09% of C++ online submissions.
// Memory Usage: 6 MB, less than 8.92% of C++ online submissions.
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string res = "", neg = "";
        if (num < 0) neg = "-";
        num = abs(num);
        while (num > 0) {
            res = to_string(num % 7) + res;
            num /= 7;
        }
        return neg + res;
    }
};
// @lc code=end