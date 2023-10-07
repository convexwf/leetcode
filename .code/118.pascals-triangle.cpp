/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
// 2022-07-30 submission
// 14/14 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.4 MB, less than 90.79% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        for (int i = 0; i < numRows; ++i) {
            res[i].resize(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};
// @lc code=end