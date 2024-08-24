/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */

// @lc code=start
// 1. 模拟
// 2023-07-17 submission
// 483/483 cases passed
// Runtime: 15 ms, faster than 75.05% of cpp online submissions.
// Memory Usage: 17.4 MB, less than 29.58% of cpp online submissions.
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
