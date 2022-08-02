/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (26.70%)
 * Likes:    5223
 * Dislikes: 233
 * Total Accepted:    405.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*' where:
 *
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
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
 * Input: s = "aa", p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "cb", p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length, p.length <= 2000
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '?' or '*'.
 *
 *
 */

// @lc code=start
// 2020-09-14 submission
// 1811/1811 cases passed
// Runtime: 36 ms, faster than 76.03% of C++ online submissions.
// Memory Usage: 6.7 MB, less than 85.48% of C++ online submissions.
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> dp(s.length() + 1, false);

        dp[0] = true;
        for (int i = 1; i <= p.length(); i++) {
            bool last_valid = dp[0];
            dp[0] = (dp[0] && p[i - 1] == '*');
            for (int j = 1; j <= s.length(); j++) {
                bool temp = dp[j];
                if (p[i - 1] == '*')
                    dp[j] = dp[j - 1] || dp[j];
                else if (p[i - 1] == '?')
                    dp[j] = last_valid;
                else
                    dp[j] = (last_valid && s[j - 1] == p[i - 1]);
                last_valid = temp;
                // cout << s[j-1] << " " << p[i-1] << " " << dp[j] << endl;
            }
        }

        return dp[s.length()];
    }
};
// @lc code=end

// @lc code=start
// 2022-08-02 submission
// 1811/1811 cases passed
// Runtime: 4 ms, faster than 98.98% of C++ online submissions.
// Memory Usage: 6.6 MB, less than 92.87% of C++ online submissions.
class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0) > 1;
    }

    int helper(string& s, string& p, int i, int j) {
        if (i == s.size() && j == p.size()) return 2;
        if (i == s.size() && p[j] != '*') return 0;
        if (j == p.size()) return 1;
        if (s[i] == p[j] || p[j] == '?') {
            return helper(s, p, i + 1, j + 1);
        }
        if (p[j] == '*') {
            if (j + 1 < p.size() && p[j + 1] == '*') {
                return helper(s, p, i, j + 1);
            }
            for (int k = 0; k <= (int)s.size() - i; ++k) {
                int res = helper(s, p, i + k, j + 1);
                if (res == 0 || res == 2) return res;
            }
        }
        return 1;
    }
};
// @lc code=end