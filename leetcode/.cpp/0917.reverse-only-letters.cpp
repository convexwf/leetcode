/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */

// @lc code=start
// 1. 双指针
// 2023-09-25 submission
// 115/115 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.5 MB, less than 8.46% of cpp online submissions.
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalpha(s[i])) {
                ++i;
            }
            while (i < j && !isalpha(s[j])) {
                --j;
            }
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
// @lc code=end
