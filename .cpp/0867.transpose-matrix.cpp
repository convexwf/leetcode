/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 */

// @lc code=start
// 1. brute force
// 2023-09-12 submission
// 36/36 cases passed
// Runtime: 10 ms, faster than 57.33% of cpp online submissions.
// Memory Usage: 10.5 MB, less than 94.62% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};
// @lc code=end
