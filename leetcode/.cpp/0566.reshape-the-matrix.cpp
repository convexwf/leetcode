/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
// 1. 模拟
// 2021-12-16 submission
// 57/57 cases passed
// Runtime: 8 ms, faster than 91.8% of cpp online submissions.
// Memory Usage: 10.6 MB, less than 81.57% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c) return mat;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int seq = i * n + j;
                res[seq / c][seq % c] = mat[i][j];
            }
        }
        return res;
    }
};
// @lc code=end
