/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
// 1. 字符串处理
// 2024-01-18 submission
// 129/129 cases passed
// Runtime: 18 ms, faster than 72.08% of cpp online submissions.
// Memory Usage: 13.8 MB, less than 72.12% of cpp online submissions.
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        return ss.substr(1, ss.size() - 2).find(s) != string::npos;
    }
};
// @lc code=end

// @lc code=start
// 2. KMP 算法
// 2024-01-18 submission
// 129/129 cases passed
// Runtime: 16 ms, faster than 81.12% of cpp online submissions.
// Memory Usage: 12 MB, less than 77.55% of cpp online submissions.
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int i = 1, j = 0, n = str.size();
        vector<int> lps(n + 1, 0);
        while (i < n) {
            if (str[i] == str[j]) {
                lps[++i] = ++j;
            }
            else if (j == 0) {
                ++i;
            }
            else {
                j = lps[j];
            }
        }
        return lps[n] && (lps[n] % (n - lps[n]) == 0);
    }
};
// @lc code=end
