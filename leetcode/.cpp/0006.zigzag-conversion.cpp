/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
// 1. 找规律
// 2022-11-14 submission
// 1157/1157 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.3 MB, less than 70.99% of cpp online submissions.
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res;
        int n = s.size();
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += 2 * numRows - 2) {
                res += s[j + i];
                if (i != 0 && i != numRows - 1 && j + 2 * numRows - 2 - i < n) {
                    res += s[j + 2 * numRows - 2 - i];
                }
            }
        }
        return res;
    }
};
// @lc code=end
