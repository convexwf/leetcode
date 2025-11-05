/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
// 1. 动态规划
// 2023-02-20 submission
// 141/141 cases passed
// Runtime: 465 ms, faster than 18.89% of cpp online submissions.
// Memory Usage: 35.2 MB, less than 28.95% of cpp online submissions.
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, true));

        string res = "";
        for (int len = 1; len <= n; ++len) {
            int i = 0, j = i + len - 1;
            while (j < n) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                }
                else if (i + 1 <= j - 1) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                // dp[i][i] 默认为 true，有以下两种情况
                // (1) len = 1
                // (2) len = 2

                if (dp[i][j] && len > res.length()) res = s.substr(i, len);
                ++i;
                ++j;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. Manacher 算法
class Solution {
public:
    string longestPalindrome(string s) {
        string t = "^";
        for (char c : s) {
            t += "#" + c;
        }
        t += "#$";
        int n = t.size();
        vector<int> p(n);
        int center = 0, right = 0;
        for (int i = 1; i < n - 1; ++i) {
            int j = 2 * center - i;
            p[i] = right > i ? min(p[j], right - i) : 0;
            while (t[i + p[i] + 1] == t[i - p[i] - 1]) {
                ++p[i];
            }
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }
        int max_len = 0, start = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (p[i] > max_len) {
                max_len = p[i];
                start = (i - p[i]) / 2;
            }
        }
        return s.substr(start, max_len);
    }
};
// @lc code=end
