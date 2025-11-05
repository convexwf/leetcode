/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
// 1. 哈希表
// 2024-06-20 submission
// 54/54 cases passed
// Runtime: 2 ms, faster than 69.02% of cpp online submissions.
// Memory Usage: 7.9 MB, less than 32.38% of cpp online submissions.
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26, 0);
        for (char ch : s) {
            cnt[ch - 'a']++;
        }
        for (char ch : t) {
            if (--cnt[ch - 'a'] < 0) {
                return ch;
            }
        }
        return ' ';
    }
};
// @lc code=end
