/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
// 1. 递归回溯
// 2022-07-20 submission
// 9/9 cases passed
// Runtime: 3 ms, faster than 82.95% of cpp online submissions.
// Memory Usage: 10.9 MB, less than 33.76% of cpp online submissions.
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> cols(n, -1);
        dfs(0, cols, res);
        return res;
    }

    void dfs(int row, vector<int>& cols, vector<vector<string>>& res) {
        int n = cols.size();
        if (row == n) {
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                board[i][cols[i]] = 'Q';
            }
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
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
