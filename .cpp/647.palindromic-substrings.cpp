/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
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
