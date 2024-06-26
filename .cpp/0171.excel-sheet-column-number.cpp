/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
// 1. 进制转化
// 2022-08-26 submission
// 1002/1002 cases passed
// Runtime: 3 ms, faster than 65.41% of cpp online submissions.
// Memory Usage: 5.8 MB, less than 98.66% of cpp online submissions.
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (char c : s) {
            res = res * 26 + (c - 'A' + 1);
        }
        return res;
    }
};
// @lc code=end
