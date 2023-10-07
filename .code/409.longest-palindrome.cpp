/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
// 2021-12-23 submission
// 95/95 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.7 MB, less than 19.2% of C++ online submissions.
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            ++m[c];
        }
        int odd_cnt = 0, even_cnt = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second % 2 == 0) even_cnt += it->second;
            else {
                even_cnt += (it->second - 1);
                odd_cnt = 1;
            }
        }
        return odd_cnt + even_cnt;
    }
};
// @lc code=end
