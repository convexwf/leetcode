/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
// 1. 动态规划
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

// @lc code=start
// 2. 记忆化搜索
// 2024-07-02 submission
// 356/356 cases passed
// Runtime: 3 ms, faster than 70.27% of cpp online submissions.
// Memory Usage: 9.9 MB, less than 17.42% of cpp online submissions.
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (j == n) return i == m;
            if (memo[i][j] != -1) return memo[i][j];
            bool firstMatch = i < m && (s[i] == p[j] || p[j] == '.');
            bool ans;
            if (j + 1 < n && p[j + 1] == '*') {
                ans = dfs(i, j + 2) || (firstMatch && dfs(i + 1, j));
            }
            else {
                ans = firstMatch && dfs(i + 1, j + 1);
            }
            return memo[i][j] = ans;
        };
        return dfs(0, 0);
    }
};
// @lc code=end
