/*
 * @lc app=leetcode id=686 lang=cpp
 *
 * [686] Repeated String Match
 */

// @lc code=start
// 1. 暴力枚举
// 2024-01-22 submission
// 59/59 cases passed
// Runtime: 11 ms, faster than 42.84% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 34.63% of cpp online submissions.
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = b.size();
        int m = a.size();
        string t = "";
        for (int i = 0; i < n / m; ++i) {
            t += a;
        }
        for (int i = 0; i < 3; ++i) {
            if (t.find(b) != string::npos) {
                return n / m + i;
            }
            t += a;
        }
        return -1;
    }
};
// @lc code=end

// @lc code=start
// 2. 字符串处理
// 2024-01-22 submission
// 59/59 cases passed
// Runtime: 284 ms, faster than 11.37% of cpp online submissions.
// Memory Usage: 7.8 MB, less than 44.35% of cpp online submissions.
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int m = A.size(), n = B.size();
        for (int i = 0; i < m; ++i) {
            int j = 0;
            while (j < n && A[(i + j) % m] == B[j]) ++j;
            if (j == n) return (i + j - 1) / m + 1;
        }
        return -1;
    }
};
// @lc code=end
