/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
// 1. 双指针
// 2022-11-14 submission
// 480/480 cases passed
// Runtime: 15 ms, faster than 43.05% of cpp online submissions.
// Memory Usage: 7.2 MB, less than 90.87% of cpp online submissions.
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
            }
            else if (!isalnum(s[right])) {
                right--;
            }
            else if (tolower(s[left++]) != tolower(s[right--])) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
