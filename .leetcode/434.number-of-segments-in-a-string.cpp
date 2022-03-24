/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (37.90%)
 * Likes:    384
 * Dislikes: 942
 * Total Accepted:    106.3K
 * Total Submissions: 280.5K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * You are given a string s, return the number of segments in the string. 
 * 
 * A segment is defined to be a contiguous sequence of non-space characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "Hello, my name is John"
 * Output: 5
 * Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "Hello"
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "love live! mu'sic forever"
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = ""
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 300
 * s consists of lower-case and upper-case English letters, digits or one of
 * the following characters "!@#$%^&*()_+-=',.:".
 * The only space character in s is ' '.
 * 
 * 
 */

// @lc code=start
// 2021-12-16 submission
// 27/27 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.1 MB, less than 90.99% of C++ online submissions.
class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        bool is_space = true;
        for (char c : s) {
            if (c != ' ' && is_space) {
                is_space = false;
                ++cnt;
            }
            if (c == ' ') is_space = true;
        }
        return cnt;
    }
};
// @lc code=end

