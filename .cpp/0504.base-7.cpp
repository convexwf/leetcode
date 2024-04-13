/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

// @lc code=start
// 2022-08-26 submission
// 241/241 cases passed
// Runtime: 3 ms, faster than 40.09% of cpp online submissions.
// Memory Usage: 6 MB, less than 8.92% of cpp online submissions.
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
