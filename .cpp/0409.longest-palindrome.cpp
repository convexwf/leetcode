/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
// 1. 计数+哈希表
// 2021-12-23 submission
// 95/95 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.7 MB, less than 19.2% of cpp online submissions.
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            ++m[c];
        }
        int count = 0;
        for (auto& [_, v] : m) {
            count += v / 2 * 2;
        }
        return count < s.size() ? count + 1 : count;
    }
};
// @lc code=end
