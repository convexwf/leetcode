/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
// 1. 双指针
// 2022-11-15 submission
// 469/469 cases passed
// Runtime: 225 ms, faster than 16.65% of cpp online submissions.
// Memory Usage: 23.9 MB, less than 49.35% of cpp online submissions.
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = (int)s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return isValid(s, left, right - 1) || isValid(s, left + 1, right);
            }
            ++left;
            --right;
        }
        return true;
    }

    bool isValid(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};
// @lc code=end
