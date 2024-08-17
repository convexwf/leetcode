/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

// @lc code=start
// 1. 双指针
// 2023-09-21 submission
// 94/94 cases passed
// Runtime: 3 ms, faster than 45.22% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 11.64% of cpp online submissions.
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, m = name.size(), n = typed.size();
        for (int j = 0; j < n; ++j) {
            if (i < m && name[i] == typed[j])
                ++i;
            else if (!j || typed[j] != typed[j - 1])
                return false;
        }
        return i == m;
    }
};
// @lc code=end
