/*
 * @lc app=leetcode id=727 lang=cpp
 *
 * [727] Minimum Window Subsequence
 */

// @lc code=start
// 1. 动态规划
class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        int start = 0, len = m + 1;
        for (int i = 1; i <= m; ++i) {
            if (dp[i][n] != -1) {
                if (i - dp[i][n] < len) {
                    start = dp[i][n];
                    len = i - dp[i][n];
                }
            }
        }
        return len == m + 1 ? "" : s1.substr(start, len);
    }
};
// @lc code=end
