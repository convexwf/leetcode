/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (32.23%)
 * Likes:    19712
 * Dislikes: 1138
 * Total Accepted:    2M
 * Total Submissions: 6.1M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: "bb"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 *
 *
 */

// @lc code=start
// 2023-02-20 submission
// 141/141 cases passed
// Runtime: 465 ms, faster than 18.89% of C++ online submissions.
// Memory Usage: 35.2 MB, less than 28.95% of C++ online submissions.
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, true));

        string res = "";
        for (int len = 1; len <= n; ++len) {
            int i = 0, j = i + len - 1;
            while (j < n) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                }
                else if (i + 1 <= j - 1) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                // dp[i][i] 默认为 true，有以下两种情况
                // (1) len = 1
                // (2) len = 2

                if (dp[i][j] && len > res.length())
                    res = s.substr(i, len);
                ++i; ++j;
            }
        }
        return res;
    }
};
// @lc code=end
