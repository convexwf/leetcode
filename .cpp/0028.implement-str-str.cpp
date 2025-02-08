/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
// 1. 朴素字符串匹配算法
// 2020-06-28 submission
// 79/79 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.2 MB, less than 69.13% of cpp online submissions.
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size(), n = needle.size();
        if (m < n) {
            return -1;
        }
        for (int i = 0; i <= m - n; ++i) {
            int j = 0;
            for (j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};
// @lc code=end

// @lc code=start
// 2. Rabin-Karp 字符串匹配算法
// 2025-02-07 submission
// 83/83 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.5 MB, less than 82.12% of cpp online submissions.
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
        }
        if (n < m) {
            return -1;
        }
        int base = 26, mod = 1000000007;
        long hash = 0, hashNeedle = 0, power = 1;
        for (int i = 0; i < m; ++i) {
            hash = (hash * base + (haystack[i] - 'a')) % mod;
            hashNeedle = (hashNeedle * base + (needle[i] - 'a')) % mod;
            power = (power * base) % mod;
        }
        if (hash == hashNeedle) {
            return 0;
        }
        for (int i = 1; i <= n - m; ++i) {
            hash = (hash * base % mod - (haystack[i - 1] - 'a') * power % mod + mod) % mod;
            hash = (hash + (haystack[i + m - 1] - 'a')) % mod;
            if (hash == hashNeedle) {
                if (haystack.substr(i, m) == needle) {
                    return i;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

// @lc code=start
// 3. KMP 字符串匹配算法
// 2025-02-07 submission
// 83/83 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.8 MB, less than 13.15% of cpp online submissions.
class Solution {
public:
    vector<int> computeLPS(const string& needle) {
        int m = needle.size();
        vector<int> lps(m);
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) {
            return 0;
        }
        if (n < m) {
            return -1;
        }

        vector<int> lps = computeLPS(needle);
        int i = 0;
        int j = 0;

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return i - j;
            }
            else if (i < n && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
