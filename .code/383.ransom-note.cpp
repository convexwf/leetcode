/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
// 2022-11-14 submission
// 127/127 cases passed
// Runtime: 62 ms, faster than 20.28% of C++ online submissions.
// Memory Usage: 8.7 MB, less than 72% of C++ online submissions.
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (char c : magazine)
            m[c]++;
        for (char c : ransomNote) {
            if (--m[c] < 0) return false;
        }
        return true;
    }
};
// @lc code=end