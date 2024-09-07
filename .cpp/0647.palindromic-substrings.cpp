/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
// 1. 中心扩展
// 2024-09-02 submission
// 132/132 cases passed
// Runtime: 3 ms, faster than 95.59% of cpp online submissions.
// Memory Usage: 7.7 MB, less than 92.6% of cpp online submissions.
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // 以当前字符为中心，向两边扩展
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; ++j) {
                ++ans;
            }
            // 以当前字符和下一个字符为中心，向两边扩展
            for (int j = 0; i - j >= 0 && i + j + 1 < n && s[i - j] == s[i + j + 1]; ++j) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划
// 2023-02-28 submission
// 130/130 cases passed
// Runtime: 17 ms, faster than 51.18% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 56.95% of cpp online submissions.
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0, n = s.length();
        vector<vector<bool>> judge(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (j + 2 > i || judge[j + 1][i - 1])) {
                    judge[j][i] = true;
                    ++res;
                }
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. Manacher 算法
// 2024-09-02 submission
// 132/132 cases passed
// Runtime: 2 ms, faster than 96.19% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 67.84% of cpp online submissions.
class Solution {
public:
    int countSubstrings(string s) {
        string t = "$#";
        for (char c : s) {
            t += c;
            t += '#';
        }
        t += '!';

        int n = t.size();
        vector<int> p(n);
        int id = 0, mx = 0, res = 0;
        for (int i = 1; i < n; ++i) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) ++p[i];
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
            res += p[i] / 2;
        }
        return res;
    }
};
// @lc code=end
