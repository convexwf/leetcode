/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
// 1. 动态规划-最长公共子序列
// 2023-06-09 submission
// 1306/1306 cases passed
// Runtime: 33 ms, faster than 29.88% of cpp online submissions.
// Memory Usage: 12.3 MB, less than 43.42% of cpp online submissions.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return m + n - 2 * dp[m][n];
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划-编辑距离
// 2023-06-09 submission
// 1306/1306 cases passed
// Runtime: 28 ms, faster than 50.07% of cpp online submissions.
// Memory Usage: 12.2 MB, less than 43.42% of cpp online submissions.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) dp[i][0] = i;
        for (int j = 1; j <= n; ++j) dp[0][j] = j;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

// @lc code=start
// 3. 动态规划-最长公共子序列+滚动数组
// 2023-06-09 submission
// 1306/1306 cases passed
// Runtime: 27 ms, faster than 54.99% of cpp online submissions.
// Memory Usage: 7.1 MB, less than 91.05% of cpp online submissions.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                }
                else {
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
                }
            }
        }
        return m + n - 2 * dp[m % 2][n];
    }
};
// @lc code=end
