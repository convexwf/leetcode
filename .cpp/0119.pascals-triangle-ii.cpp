/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
// 2022-07-30 submission
// 34/34 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.4 MB, less than 79.99% of cpp online submissions.
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret{1};
        for (int num = 1; num < rowIndex + 1; num++) {
            ret.push_back((int64_t)ret.back() * (rowIndex + 1 - num) / num);
        }
        return ret;
    }
};
// @lc code=end
