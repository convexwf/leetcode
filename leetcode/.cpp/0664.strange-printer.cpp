/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 */

// @lc code=start
// 1. 动态规划
// 2023-08-29 submission
// 200/200 cases passed
// Runtime: 45 ms, faster than 43.13% of cpp online submissions.
// Memory Usage: 9.4 MB, less than 64.63% of cpp online submissions.
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                }
                else {
                    int minn = INT_MAX;
                    for (int k = i; k < j; k++) {
                        minn = min(minn, dp[i][k] + dp[k + 1][j]);
                    }
                    dp[i][j] = minn;
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

// @lc code=start
// 2. 记忆化搜索
// 2023-08-29 submission
// 200/200 cases passed
// Runtime: 27 ms, faster than 61.11% of cpp online submissions.
// Memory Usage: 9.5 MB, less than 27.44% of cpp online submissions.
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        memo = vector<vector<int>>(n, vector<int>(n));
        return dfs(s, 0, n - 1);
    }

private:
    vector<vector<int>> memo;
    int dfs(const string& s, int i, int j) {
        if (i > j) return 0;
        if (memo[i][j] != 0) return memo[i][j];
        memo[i][j] = dfs(s, i + 1, j) + 1;
        for (int k = i + 1; k <= j; ++k) {
            if (s[i] == s[k]) {
                memo[i][j] = min(memo[i][j], dfs(s, i, k - 1) + dfs(s, k + 1, j));
            }
        }
        return memo[i][j];
    }
};
// @lc code=end
