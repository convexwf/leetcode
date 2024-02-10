/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
// 2021-03-18 submission
// 64/64 cases passed
// Runtime: 8 ms, faster than 97.04% of C++ online submissions.
// Memory Usage: 8.6 MB, less than 91.9% of C++ online submissions.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m[256] = {0};   // 数据类型不能用char！！！
        int len = p.length();
        for (char c : p) {
            ++m[c];
        }

        int l = -1;
        vector<int> res;
        for (int i = 0; i < s.length(); i++) {
            --m[s[i]];
            while (m[s[i]] < 0) ++m[s[++l]];
            if (i - l == len) res.push_back(l + 1);
        }
        return res;
    }
};
// @lc code=end
