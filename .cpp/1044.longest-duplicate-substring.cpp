/*
 * @lc app=leetcode id=1044 lang=cpp
 *
 * [1044] Longest Duplicate Substring
 */

// @lc code=start
// 1. 字符串哈希+二分查找
// 2025-03-04 submission
// 68/68 cases passed
// Runtime: 1270 ms, faster than 39.18% of cpp online submissions.
// Memory Usage: 437.5 MB, less than 21.91% of cpp online submissions.
class Solution {
public:
    string longestDupSubstring(string s) {
        const long MOD = 1e9 + 7;
        const long BASE = 26;
        int n = s.length();

        vector<long> power(n + 1, 1);
        vector<long> hash(n + 1);

        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * BASE) % MOD;
            hash[i] = (hash[i - 1] * BASE + s[i - 1] - 'a') % MOD;
        }

        // Get the hash value of substring s[i, j)
        function<long(int, int)> getHash = [&](int i, int j) {
            return (hash[j] - hash[i] * power[j - i] % MOD + MOD) % MOD;
        };

        // Get the substring of input length that appears more than once
        function<string(int)> getSubstring = [&](int len) {
            unordered_map<long, vector<int>> hashToIndex;
            for (int i = 0; i + len <= n; i++) {
                long h = getHash(i, i + len);
                if (hashToIndex.count(h)) {
                    for (int j : hashToIndex[h]) {
                        if (s.substr(i, len) == s.substr(j, len)) {
                            return s.substr(i, len);
                        }
                    }
                }
                hashToIndex[h].push_back(i);
            }
            return string();
        };

        int left = 0, right = n;
        string res;
        while (left < right) {
            int mid = left + (right - left) / 2;
            string sub = getSubstring(mid);
            if (sub.empty()) {
                right = mid;
            }
            else {
                res = sub;
                left = mid + 1;
            }
        }
        return res;
    }
};
// @lc code=end
