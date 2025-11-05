/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
// 1. KMP 算法
// 2023-02-06 submission
// 121/121 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.9 MB, less than 50% of cpp online submissions.
class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> lps(t.size(), 0);
        for (int i = 1; i < t.size(); ++i) {
            int j = lps[i - 1];
            while (j > 0 && t[i] != t[j]) {
                j = lps[j - 1];
            }
            lps[i] = (j += t[i] == t[j]);
        }
        return r.substr(0, s.size() - lps.back()) + s;
    }
};
// @lc code=end

// @lc code=start
// 2. 字符串哈希
// 2025-02-08 submission
// 126/126 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 11.9 MB, less than 98.35% of cpp online submissions.
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        long base = 26, mod = 1e9 + 7;
        long left = 0, right = 0, mul = 1;
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            left = (left * base + s[i] - 'a') % mod;
            right = (right + mul * (s[i] - 'a')) % mod;
            if (left == right) {
                maxLen = i + 1;
            }
            mul = mul * base % mod;
        }
        string add = s.substr(maxLen);
        reverse(add.begin(), add.end());
        return add + s;
    }
};
// @lc code=end
