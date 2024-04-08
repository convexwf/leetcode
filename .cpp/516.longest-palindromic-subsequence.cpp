/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
// 2023-02-20 submission
// 86/86 cases passed
// Runtime: 106 ms, faster than 78.85% of cpp online submissions.
// Memory Usage: 73 MB, less than 56.41% of cpp online submissions.
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                if (s[i] != s[j]) {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
                else if (i + 1 <= j - 1) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                    dp[i][j] = 2;
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end
