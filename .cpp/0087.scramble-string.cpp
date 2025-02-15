/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
// 1. 递归
// 2025-02-12 submission
// 290/290 cases passed
// Runtime: 10 ms, faster than 83.72% of cpp online submissions.
// Memory Usage: 17.4 MB, less than 65.17% of cpp online submissions.
class Solution {
public:
    bool isIsomorphic(const string& s1, const string& s2) {
        vector<int> cnt(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            ++cnt[s1[i] - 'a'];
            --cnt[s2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0) {
                return false;
            }
        }
        return true;
    }

    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        if (s1.size() != s2.size()) {
            return false;
        }
        if (!isIsomorphic(s1, s2)) {
            return false;
        }
        if (memo.count(s1 + "#" + s2)) {
            return memo[s1 + "#" + s2];
        }
        int n = s1.size();
        for (int i = 1; i < n; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[s1 + "#" + s2] = true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[s1 + "#" + s2] = true;
            }
        }
        return memo[s1 + "#" + s2] = false;
    }

private:
    unordered_map<string, bool> memo;
};
// @lc code=end

// @lc code=start
// 2025-02-12 submission
// 290/290 cases passed
// Runtime: 34 ms, faster than 50.36% of cpp online submissions.
// Memory Usage: 12.8 MB, less than 90.92% of cpp online submissions.
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        if (s1 == s2) {
            return true;
        }
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                for (int j = 0; j + len <= n; ++j) {
                    if (len == 1) {
                        dp[i][j][len] = s1[i] == s2[j];
                    }
                    else {
                        for (int l = 1; l < len && !dp[i][j][len]; ++l) {
                            dp[i][j][len] = (dp[i][j][l] && dp[i + l][j + l][len - l]) ||
                                            (dp[i][j + len - l][l] && dp[i + l][j][len - l]);
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
// @lc code=end
