/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
// 1. 记忆化搜索
// 2023-12-22 submission
// 58/58 cases passed
// Runtime: 44 ms, faster than 65.88% of cpp online submissions.
// Memory Usage: 28.8 MB, less than 58.43% of cpp online submissions.
class Solution {
public:
    int dfs(string& s, int i, int j, vector<vector<int>>& memo) {
        if (i >= j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        if (s[i] == s[j]) return memo[i][j] = dfs(s, i + 1, j - 1, memo);
        return memo[i][j] = min(dfs(s, i + 1, j, memo), dfs(s, i, j - 1, memo)) + 1;
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(s, 0, n - 1, memo);
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划
// 2023-12-22 submission
// 58/58 cases passed
// Runtime: 32 ms, faster than 83.85% of cpp online submissions.
// Memory Usage: 28.7 MB, less than 67.29% of cpp online submissions.
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
        }
        for (int len = 1; len < n; ++len) {
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end
