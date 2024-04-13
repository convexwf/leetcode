/*
 * @lc app=leetcode id=880 lang=cpp
 *
 * [880] Decoded String at Index
 */

// @lc code=start
// 1. 逆向解码
// 2024-02-07 submission
// 46/46 cases passed
// Runtime: 3 ms, faster than 22.32% of cpp online submissions.
// Memory Usage: 7.2 MB, less than 16.95% of cpp online submissions.
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long size = 0;
        for (char c : s) {
            if (isdigit(c)) {
                size *= c - '0';
            }
            else {
                size++;
            }
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            k %= size;
            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }
            if (isdigit(s[i])) {
                size /= s[i] - '0';
            }
            else {
                size--;
            }
        }
        return "";
    }
};
// @lc code=end
