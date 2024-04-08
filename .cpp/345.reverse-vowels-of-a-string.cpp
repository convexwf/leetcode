/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
// 2021-12-16 submission
// 480/480 cases passed
// Runtime: 8 ms, faster than 70.15% of cpp online submissions.
// Memory Usage: 8 MB, less than 38.59% of cpp online submissions.
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> m{'a', 'i', 'u', 'e', 'o'};
        int n = s.length();
        int l = 0, r = n - 1;
        while (l < r) {
            while (l < n && !m.count(tolower(s[l]))) ++l;
            while (r >= 0 && !m.count(tolower(s[r]))) --r;
            if (l < r) {
                swap(s[l], s[r]);
                ++l;
                --r;
            }
        }
        return s;
    }
};
// @lc code=end
