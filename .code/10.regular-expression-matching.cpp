/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (28.28%)
 * Likes:    8587
 * Dislikes: 1320
 * Total Accepted:    707.4K
 * Total Submissions: 2.5M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string s and a pattern p, implement regular expression
 * matching with support for '.' and '*' where:
 *
 *
 * '.' Matches any single character.​​​​
 * '*' Matches zero or more of the preceding element.
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aa", p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "ab", p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 20
 * 1 <= p.length <= 30
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '.', and '*'.
 * It is guaranteed for each appearance of the character '*', there will be a
 * previous valid character to match.
 *
 *
 */

// @lc code=start
// TLE
class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }

    bool helper(string& s, string& p, int sp, int pp) {
        if (pp == p.length()) return sp == s.length();
        if (pp + 1 == p.length()) {
            return sp + 1 == s.length() && (p[pp] == '.' || p[pp] == s[sp]);
        }
        if(p[pp + 1] == '*') {
            if (sp == s.length() && (p[pp] == '.' || p[pp] == s[sp]) && helper(s, p, sp+1, pp)) return true;
            return helper(s, p, sp, pp + 2);
        }
        if(sp < s.length() && (p[pp] == '.' || p[pp] == s[sp])) return helper(s, p, sp+1, pp+1);
        else return false;
    }
};
// @lc code=end

// @lc code=start
// 2023-02-02 submission
// 353/353 cases passed
// Runtime: 10 ms, faster than 51.8% of C++ online submissions.
// Memory Usage: 7 MB, less than 66.86% of C++ online submissions.
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > 1 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                } else {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end