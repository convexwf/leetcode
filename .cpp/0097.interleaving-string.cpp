/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
// 1. 动态规划
// 2025-02-13 submission
// 106/106 cases passed
// Runtime: 2 ms, faster than 67.17% of cpp online submissions.
// Memory Usage: 9.4 MB, less than 55.14% of cpp online submissions.
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), t = s3.length();
        if (n + m != t) {
            return false;
        }
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                if (s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划-空间优化
// 2020-09-14 submission
// 106/106 cases passed
// Runtime: 6 ms, faster than 56.57% of cpp online submissions.
// Memory Usage: 6.5 MB, less than 72.19% of cpp online submissions.
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        vector<bool> dp(s2.length() + 1, false);
        dp[0] = true;
        for (int i = 0; i <= s1.length(); ++i) {
            for (int j = 0; j <= s2.length(); ++j) {
                if (i > 0) {
                    dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
                }
                if (j > 0) {
                    dp[j] = dp[j] || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[s2.length()];
    }
};
// @lc code=end

// @lc code=start
// 3. 记忆化搜索
// 2023-02-02 submission
// 106/106 cases passed
// Runtime: 3 ms, faster than 82.88% of cpp online submissions.
// Memory Usage: 10.7 MB, less than 32.05% of cpp online submissions.
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), t = s3.length();
        if (n + m != t) {
            return false;
        }
        unordered_set<int> visited;
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) {
            if (visited.count(i * t + j)) {
                return false;
            }
            if (i == n) {
                return s2.substr(j) == s3.substr(k);
            }
            if (j == m) {
                return s1.substr(i) == s3.substr(k);
            }
            if (s1[i] == s3[k] && dfs(i + 1, j, k + 1)) {
                return true;
            }
            if (s2[j] == s3[k] && dfs(i, j + 1, k + 1)) {
                return true;
            }
            visited.insert(i * t + j);
            return false;
        };
        return dfs(0, 0, 0);
    }
};
// @lc code=end
