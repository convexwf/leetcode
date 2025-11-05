/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
// 1. 递归回溯
// 2024-03-05 submission
// 9/9 cases passed
// Runtime: 6 ms, faster than 28.81% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 45.11% of cpp online submissions.
class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n, 0), dia1(2 * n - 1, 0), dia2(2 * n - 1, 0);
        int res = 0;
        dfs(0, n, col, dia1, dia2, res);
        return res;
    }

    void dfs(int row, int n, vector<bool>& col, vector<bool>& dia1, vector<bool>& dia2, int& res) {
        if (row == n) {
            res++;
            return;
        }
        for (int c = 0; c < n; c++) {
            if (col[c] || dia1[row + c] || dia2[row - c + n - 1]) continue;
            col[c] = dia1[row + c] = dia2[row - c + n - 1] = true;
            dfs(row + 1, n, col, dia1, dia2, res);
            col[c] = dia1[row + c] = dia2[row - c + n - 1] = false;
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 递归回溯+空间优化
// 2022-07-20 submission
// 9/9 cases passed
// Runtime: 3 ms, faster than 86.88% of cpp online submissions.
// Memory Usage: 6.1 MB, less than 77.55% of cpp online submissions.
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> cols(n, -1);
        int res = 0;
        dfs(0, cols, res);
        return res;
    }

    void dfs(int row, vector<int>& cols, int& res) {
        if (row == cols.size()) {
            res++;
            return;
        }
        for (int col = 0; col < cols.size(); col++) {
            if (isValid(row, col, cols)) {
                cols[row] = col;
                dfs(row + 1, cols, res);
                cols[row] = -1;
            }
        }
    }

    bool isValid(int row, int col, vector<int>& cols) {
        for (int i = 0; i < row; i++) {
            if (cols[i] == col || abs(row - i) == abs(col - cols[i])) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
