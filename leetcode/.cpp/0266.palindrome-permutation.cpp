/*
 * @lc app=leetcode id=266 lang=cpp
 *
 * [266] Palindrome Permutation
 */

// @lc code=start
// 1. 哈希表
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> cnt;
        for (char c : s) {
            cnt[c]++;
        }
        int odd = 0;
        for (auto [_, v] : cnt) {
            if (v % 2 == 1) {
                odd++;
            }
        }
        return odd <= 1;
    }
};
// @lc code=end
