/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
// 1. 哈希表
// 2022-11-14 submission
// 37/37 cases passed
// Runtime: 3 ms, faster than 99.41% of cpp online submissions.
// Memory Usage: 7.1 MB, less than 96.72% of cpp online submissions.
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> m(26);
        for (int i = 0; i < s.size(); ++i) ++m[s[i] - 'a'];
        for (int i = 0; i < t.size(); ++i) {
            if (--m[t[i] - 'a'] < 0) return false;
        }
        return true;
    }
};
// @lc code=end
