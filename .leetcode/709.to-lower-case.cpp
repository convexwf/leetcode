/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 *
 * https://leetcode.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (80.84%)
 * Likes:    888
 * Dislikes: 2173
 * Total Accepted:    312.4K
 * Total Submissions: 386.3K
 * Testcase Example:  '"Hello"'
 *
 * Given a string s, return the string after replacing every uppercase letter
 * with the same lowercase letter.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "Hello"
 * Output: "hello"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "here"
 * Output: "here"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "LOVELY"
 * Output: "lovely"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s consists of printable ASCII characters.
 * 
 * 
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

