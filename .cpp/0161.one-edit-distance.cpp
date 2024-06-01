/*
 * @lc app=leetcode id=161 lang=cpp
 *
 * [161] One Edit Distance
 */

// @lc code=start
// 1. 逐位比较
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        for (int i = 0; i < min(m, n); i++) {
            if (s[i] != t[i]) {
                if (m == n) {
                    return s.substr(i + 1) == t.substr(i + 1);
                }
                else if (m < n) {
                    return s.substr(i) == t.substr(i + 1);
                }
                else {
                    return s.substr(i + 1) == t.substr(i);
                }
            }
        }
        return abs(m - n) == 1;
    }
};
// @lc code=end
