/*
 * @lc app=leetcode id=1062 lang=cpp
 *
 * [1062] Longest Repeating Substring
 */

// @lc code=start
// 1. 动态规划
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j] && i == 0) {
                    dp[i][j] = 1;
                }
                else if (s[i] == s[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end
