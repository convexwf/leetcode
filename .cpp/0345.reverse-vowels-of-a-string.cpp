/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
// 1. 双指针
// 2021-12-16 submission
// 480/480 cases passed
// Runtime: 3 ms, faster than 96.05% of cpp online submissions.
// Memory Usage: 8 MB, less than 14.12% of cpp online submissions.
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> m{'a', 'i', 'u', 'e', 'o', 'A', 'I', 'U', 'E', 'O'};
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !m.count(s[l])) l++;
            while (l < r && !m.count(s[r])) r--;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};
// @lc code=end
