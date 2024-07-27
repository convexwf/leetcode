/*
 * @lc app=leetcode id=408 lang=cpp
 *
 * [408] Valid Word Abbreviation
 */

// @lc code=start
// 1. 双指针+模拟
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        int num = 0;
        while (i < word.size() && j < abbr.size()) {
            if (isdigit(abbr[j])) {
                if (num == 0 && abbr[j] == '0') {
                    return false;
                }
                num = num * 10 + abbr[j] - '0';
            }
            else {
                i += num;
                num = 0;
                if (i >= word.size() || word[i] != abbr[j]) {
                    return false;
                }
                ++i;
            }
            ++j;
        }
        i += num;
        return i == word.size() && j == abbr.size();
    }
};
// @lc code=end
