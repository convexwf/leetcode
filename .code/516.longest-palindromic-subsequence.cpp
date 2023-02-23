/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (60.91%)
 * Likes:    6899
 * Dislikes: 274
 * Total Accepted:    321.2K
 * Total Submissions: 527.2K
 * Testcase Example:  '"bbbab"'
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 *
 * A subsequence is a sequence that can be derived from another sequence by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "bbbab"
 * Output: 4
 * Explanation: One possible longest palindromic subsequence is "bbbb".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: 2
 * Explanation: One possible longest palindromic subsequence is "bb".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consists only of lowercase English letters.
 *
 *
 */

// @lc code=start
// 2023-02-20 submission
// 86/86 cases passed
// Runtime: 106 ms, faster than 78.85% of C++ online submissions.
// Memory Usage: 73 MB, less than 56.41% of C++ online submissions.
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                if (s[i] != s[j]) {
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
                else if (i + 1 <= j - 1) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else dp[i][j] = 2;
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end