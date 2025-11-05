/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
// 1. 排序
// 2022-07-18 submission
// 124/124 cases passed
// Runtime: 3 ms, faster than 92.12% of cpp online submissions.
// Memory Usage: 9.3 MB, less than 51.61% of cpp online submissions.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        int i = 0, len = min(strs[0].size(), strs.back().size());
        while (i < len && strs[0][i] == strs.back()[i]) ++i;
        return strs[0].substr(0, i);
    }
};
// @lc code=end
