/*
 * @lc app=leetcode id=311 lang=cpp
 *
 * [311] Sparse Matrix Multiplication
 */

// @lc code=start
// 1. 直接相乘
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat1[0].size(), n = mat2[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int t = 0; t < k; ++t) {
                    res[i][j] += mat1[i][t] * mat2[t][j];
                }
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 预处理
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat1[0].size(), n = mat2[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<vector<pair<int, int>>> row(m), col(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < k; ++j) {
                if (mat1[i][j] != 0) {
                    row[i].push_back({j, mat1[i][j]});
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                if (mat2[j][i] != 0) {
                    col[i].push_back({j, mat2[j][i]});
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (auto& [k, val1] : row[i]) {
                for (auto& [j, val2] : col[k]) {
                    res[i][j] += val1 * val2;
                }
            }
        }
        return res;
    }
};
// @lc code=end
