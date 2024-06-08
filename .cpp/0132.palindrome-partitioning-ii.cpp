/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
// 1. 动态规划
// 2024-06-07 submission
// 37/37 cases passed
// Runtime: 1491 ms, faster than 45.42% of cpp online submissions.
// Memory Usage: 7.7 MB, less than 85.62% of cpp online submissions.
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        for (int i = 1; i <= n; ++i) {
            dp[i] = i - 1;
            for (int j = 0; j < i; ++j) {
                if (isPalindrome(s, j, i - 1)) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n];
    }

    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划+优化
// 2023-02-27 submission
// 36/36 cases passed
// Runtime: 28 ms, faster than 92.06% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 45.56% of cpp online submissions.
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> memo(n, vector<bool>(n, false));
        vector<int> dp(n + 1, -1);
        for (int i = 1; i <= n; ++i) {
            dp[i] = i - 1;
            for (int j = 0; j < i; ++j) {
                if (s[j] == s[i - 1] && (i - j <= 2 || memo[j + 1][i - 2])) {
                    memo[j][i - 1] = true;
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end
