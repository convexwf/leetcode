/*
 * @lc app=leetcode id=777 lang=cpp
 *
 * [777] Swap Adjacent in LR String
 */

// @lc code=start
// 1. 双指针
// 2023-11-24 submission
// 94/94 cases passed
// Runtime: 8 ms, faster than 47.9% of cpp online submissions.
// Memory Usage: 7.7 MB, less than 74.13% of cpp online submissions.
class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0, j = 0;
        while (i < start.size() || j < end.size()) {
            while (i < start.size() && start[i] == 'X') ++i;
            while (j < end.size() && end[j] == 'X') ++j;
            if (i == start.size() && j == end.size()) return true;
            if (i == start.size() || j == end.size()) return false;
            if (start[i] != end[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            ++i;
            ++j;
        }
        return true;
    }
};
// @lc code=end
