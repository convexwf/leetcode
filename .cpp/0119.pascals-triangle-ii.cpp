/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
// 1. 数学方法
// 2022-07-30 submission
// 34/34 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.4 MB, less than 79.99% of cpp online submissions.
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for (int k = 1; k < rowIndex; ++k) {
            res[k] = (long)res[k - 1] * (rowIndex - k + 1) / k;
        }
        return res;
    }
};
// @lc code=end
