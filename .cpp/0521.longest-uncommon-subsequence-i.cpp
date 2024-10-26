/*
 * @lc app=leetcode id=521 lang=cpp
 *
 * [521] Longest Uncommon Subsequence I
 */

// @lc code=start
// 1. 字符串比较
// 2023-05-23 submission
// 41/41 cases passed
// Runtime: 0 ms, faster than % of cpp online submissions.
// Memory Usage:  MB, less than 99.08% of cpp online submissions.
class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};
// @lc code=end
