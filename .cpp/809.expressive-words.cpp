/*
 * @lc app=leetcode id=809 lang=cpp
 *
 * [809] Expressive Words
 */

// @lc code=start
// 1. 双指针
// 2023-12-13 submission
// 35/35 cases passed
// Runtime: 6 ms, faster than 48.92% of cpp online submissions.
// Memory Usage: 7.9 MB, less than 75.23% of cpp online submissions.
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        for (auto& t : words) {
            if (check(s, t)) {
                ++res;
            }
        }
        return res;
    }

private:
    bool check(string& s, string& t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] != t[j]) {
                return false;
            }
            int c1 = 1, c2 = 1;
            while (i + 1 < s.size() && s[i] == s[i + 1]) {
                ++i;
                ++c1;
            }
            while (j + 1 < t.size() && t[j] == t[j + 1]) {
                ++j;
                ++c2;
            }
            if (c1 < c2 || (c1 != c2 && c1 < 3)) {
                return false;
            }
            ++i;
            ++j;
        }
        return i == s.size() && j == t.size();
    }
};
// @lc code=end
