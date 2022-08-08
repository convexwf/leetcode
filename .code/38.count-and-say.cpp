/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Medium (49.25%)
 * Likes:    1760
 * Dislikes: 4117
 * Total Accepted:    651.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is a sequence of digit strings defined by the
 * recursive formula:
 * 
 * 
 * countAndSay(1) = "1"
 * countAndSay(n) is the way you would "say" the digit string from
 * countAndSay(n-1), which is then converted into a different digit string.
 * 
 * 
 * To determine how you "say" a digit string, split it into the minimal number
 * of substrings such that each substring contains exactly one unique digit.
 * Then for each substring, say the number of digits, then say the digit.
 * Finally, concatenate every said digit.
 * 
 * For example, the saying and conversion for digit string "3322251":
 * 
 * Given a positive integer n, return the n^th term of the count-and-say
 * sequence.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: "1"
 * Explanation: This is the base case.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4
 * Output: "1211"
 * Explanation:
 * countAndSay(1) = "1"
 * countAndSay(2) = say "1" = one 1 = "11"
 * countAndSay(3) = say "11" = two 1's = "21"
 * countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 30
 * 
 * 
 */

// @lc code=start
// 2022-08-07 submission
// 30/30 cases passed
// Runtime: 10 ms, faster than 68.15% of C++ online submissions.
// Memory Usage: 6.6 MB, less than 78.34% of C++ online submissions.
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string res = "1";
        while (--n) {
            string cur = "";
            for (int i = 0; i < res.size(); ++i) {
                int cnt = 1;
                while (i + 1 < res.size() && res[i] == res[i + 1]) {
                    ++cnt;
                    ++i;
                }
                cur += to_string(cnt) + res[i];
            }
            res = cur;
        }
        return res;
    }
};
// @lc code=end