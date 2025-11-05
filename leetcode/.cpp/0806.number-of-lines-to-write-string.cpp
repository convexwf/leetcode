/*
 * @lc app=leetcode id=806 lang=cpp
 *
 * [806] Number of Lines To Write String
 */

// @lc code=start
// 1. 模拟
// 2023-08-30 submission
// 27/27 cases passed
// Runtime: 3 ms, faster than 41.52% of cpp online submissions.
// Memory Usage: 6.8 MB, less than 53.21% of cpp online submissions.
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1, width = 0;
        for (char c : s) {
            int w = widths[c - 'a'];
            if (width + w > 100) {
                lines++;
                width = w;
            }
            else {
                width += w;
            }
        }
        return {lines, width};
    }
};
// @lc code=end
