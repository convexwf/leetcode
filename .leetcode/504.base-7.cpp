/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (47.11%)
 * Likes:    405
 * Dislikes: 184
 * Total Accepted:    78.6K
 * Total Submissions: 166.8K
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
// 2021-12-15 submission
// 241/241 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6 MB, less than 51.71% of C++ online submissions.
class Solution {
public:
    string convertToBase7(int num) {
        bool minus = (num < 0);
        num = abs(num);
        string res;
        while(num) {
            res.append(1, '0' + num % 7);
            num /= 7;
        }
        if (minus) res.append(1, '-');
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};
// @lc code=end

