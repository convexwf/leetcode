/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
// 2022-07-21 submission
// 58/58 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.6 MB, less than 52.03% of C++ online submissions.
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int validNum = 0;
        int index = len - 1;
        while (s[index] == ' ') index--;
        for (; index >= 0; index--) {
            if (isalpha(s[index]))
                validNum++;
            else
                break;
        }
        return validNum;
    }
};
// @lc code=end