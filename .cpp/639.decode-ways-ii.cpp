/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 */

// @lc code=start
// 1. 动态规划
// 2024-02-06 submission
// 218/218 cases passed
// Runtime: 26 ms, faster than 96.23% of cpp online submissions.
// Memory Usage: 24.4 MB, less than 47.96% of cpp online submissions.
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int n = s.size();
        const int MOD = 1e9 + 7;
        vector<long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '*' ? 9 : 1;
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] == '*') {
                dp[i] = 9 * dp[i - 1] % MOD;
                if (s[i - 2] == '1') {
                    dp[i] += 9 * dp[i - 2];
                }
                else if (s[i - 2] == '2') {
                    dp[i] += 6 * dp[i - 2];
                }
                else if (s[i - 2] == '*') {
                    dp[i] += 15 * dp[i - 2];
                }
            }
            else if (s[i - 1] == '0') {
                if (s[i - 2] == '1' || s[i - 2] == '2') {
                    dp[i] = dp[i - 2];
                }
                else if (s[i - 2] == '*') {
                    dp[i] = 2 * dp[i - 2];
                }
            }
            else { // s[i - 1] == '0'~'9'
                dp[i] = dp[i - 1];
                if (s[i - 2] == '1') {
                    dp[i] += dp[i - 2];
                }
                else if (s[i - 2] == '2') {
                    if (s[i - 1] >= '1' && s[i - 1] <= '6') {
                        dp[i] += dp[i - 2];
                    }
                }
                else if (s[i - 2] == '*') {
                    if (s[i - 1] >= '1' && s[i - 1] <= '6') {
                        dp[i] += 2 * dp[i - 2];
                    }
                    else { // s[i - 1] >= '7' && s[i - 1] <= '9'
                        dp[i] += dp[i - 2];
                    }
                }
            }
            if (dp[i] == 0) return 0;
            dp[i] %= MOD;
        }
        return dp[n];
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划+优化空间
// 2024-02-06 submission
// 218/218 cases passed
// Runtime: 25 ms, faster than 97.29% of cpp online submissions.
// Memory Usage: 13.6 MB, less than 78.13% of cpp online submissions.
class Solution {
public:
    int numDecodings(string s) {
        long e0 = 1, e1 = 0, e2 = 0, f0 = 0, M = 1e9 + 7;
        for (char c : s) {
            if (c == '*') {
                f0 = 9 * e0 + 9 * e1 + 6 * e2;
                e1 = e0;
                e2 = e0;
            }
            else {
                f0 = (c > '0') * e0 + e1 + (c <= '6') * e2;
                e1 = (c == '1') * e0;
                e2 = (c == '2') * e0;
            }
            e0 = f0 % M;
        }
        return e0;
    }
};
// @lc code=end
