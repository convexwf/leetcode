/*
 * @lc app=leetcode id=940 lang=cpp
 *
 * [940] Distinct Subsequences II
 */

// @lc code=start
// 1. 动态规划
// 2025-02-11 submission
// 110/110 cases passed
// Runtime: 1 ms, faster than 62.7% of cpp online submissions.
// Memory Usage: 8.9 MB, less than 74.37% of cpp online submissions.
class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod = 1e9 + 7;
        vector<long> dp(26);
        for (char& c : s) {
            int i = c - 'a';
            dp[i] = accumulate(dp.begin(), dp.end(), 1l) % mod;
        }
        return accumulate(dp.begin(), dp.end(), 0l) % mod;
    }
};
// @lc code=end

// @lc code=start
// 1. 动态规划
// 2025-02-11 submission
// 110/110 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.9 MB, less than 85.58% of cpp online submissions.
class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod = 1e9 + 7;
        vector<long> dp(26, 0);
        long ans = 0;
        for (const char& c : s) {
            int i = c - 'a';
            long add = ans + 1 - dp[i];
            ans = (ans + add + mod) % mod;
            dp[i] = (dp[i] + add) % mod;
        }
        return ans;
    }
};
// @lc code=end
