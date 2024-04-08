/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
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
        if (p[pp + 1] == '*') {
            if (sp == s.length() && (p[pp] == '.' || p[pp] == s[sp]) && helper(s, p, sp + 1, pp))
                return true;
            return helper(s, p, sp, pp + 2);
        }
        if (sp < s.length() && (p[pp] == '.' || p[pp] == s[sp]))
            return helper(s, p, sp + 1, pp + 1);
        else
            return false;
    }
};
// @lc code=end

// @lc code=start
// 2023-02-02 submission
// 353/353 cases passed
// Runtime: 10 ms, faster than 51.8% of cpp online submissions.
// Memory Usage: 7 MB, less than 66.86% of cpp online submissions.
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > 1 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] ||
                               (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
                else {
                    dp[i][j] =
                        i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
