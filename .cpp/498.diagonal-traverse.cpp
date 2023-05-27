/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 */

// @lc code=start
// 1. 轨迹模拟
// 2023-05-24 submission
// 32/32 cases passed
// Runtime: 19 ms, faster than 99.41% of cpp online submissions.
// Memory Usage: 17.6 MB, less than 99.61% of cpp online submissions.
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res(m * n);
        int row = 0, col = 0;
        for (int i = 0; i < m * n; i++) {
            res[i] = mat[row][col];
            if ((row + col) % 2 == 0) { // 向上走
                if (col == n - 1)
                    row++; // 先判断右边界
                else if (row == 0)
                    col++; // 再判断上边界
                else {
                    row--;
                    col++;
                }
            }
            else { // 向下走
                if (row == m - 1)
                    col++; // 先判断下边界
                else if (col == 0)
                    row++; // 再判断左边界
                else {
                    row++;
                    col--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 分层
// 2023-05-24 submission
// 32/32 cases passed
// Runtime: 31 ms, faster than 69.55% of cpp online submissions.
// Memory Usage: 17.6 MB, less than 94.99% of cpp online submissions.
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        int m = mat.size(), n = mat[0].size(), k = 0;
        vector<int> res(m * n);
        for (int i = 0; i < m + n - 1; ++i) {
            int low = max(0, i - n + 1), high = min(i, m - 1);
            if (i % 2 == 0) {
                for (int j = high; j >= low; --j) {
                    res[k++] = mat[j][i - j];
                }
            }
            else {
                for (int j = low; j <= high; ++j) {
                    res[k++] = mat[j][i - j];
                }
            }
        }
        return res;
    }
};
// @lc code=end