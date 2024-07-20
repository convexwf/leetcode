/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
// 1. 位操作+回溯
// 2024-07-19 submission
// 6/6 cases passed
// Runtime: 2 ms, faster than 98.17% of cpp online submissions.
// Memory Usage: 7.9 MB, less than 23.27% of cpp online submissions.
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0), col(9, 0), block(9, 0);
        vector<pair<int, int>> empty;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    empty.push_back({i, j});
                }
                else {
                    int k = board[i][j] - '1';
                    row[i] |= (1 << k);
                    col[j] |= (1 << k);
                    block[(i / 3) * 3 + j / 3] |= (1 << k);
                }
            }
        }
        dfs(board, row, col, block, empty, 0);
    }

    bool dfs(vector<vector<char>>& board, vector<int>& row, vector<int>& col, vector<int>& block,
             vector<pair<int, int>>& empty, int index) {
        if (index == empty.size()) {
            return true;
        }
        int i = empty[index].first, j = empty[index].second;
        int m = (i / 3) * 3 + j / 3;
        for (int k = 0; k < 9; ++k) {
            if ((row[i] & (1 << k)) == 0 && (col[j] & (1 << k)) == 0 &&
                (block[m] & (1 << k)) == 0) {
                row[i] |= (1 << k);
                col[j] |= (1 << k);
                block[m] |= (1 << k);
                board[i][j] = k + '1';
                if (dfs(board, row, col, block, empty, index + 1)) {
                    return true;
                }
                row[i] &= ~(1 << k);
                col[j] &= ~(1 << k);
                block[m] &= ~(1 << k);
            }
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2. 位操作+回溯+状态优化
// 2022-08-07 submission
// 6/6 cases passed
// Runtime: 5 ms, faster than 97.74% of cpp online submissions.
// Memory Usage: 6.4 MB, less than 49.84% of cpp online submissions.
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> valid(9, 0);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (isdigit(board[i][j])) {
                    bitSet(valid, board[i][j] - '1', i, j);
                }
            }
        }
        backtrack(board, valid, 0);
    }

    bool backtrack(vector<vector<char>>& board, vector<int>& valid, int level) {
        if (level == 81) return true;
        int x = level / 9, y = level % 9;
        if (board[x][y] == '.') {
            for (int i = 0; i < 9; ++i) {
                if (bitCheck(valid, i, x, y)) continue;
                bitSet(valid, i, x, y);
                board[x][y] = '1' + i;
                if (backtrack(board, valid, 1 + level)) {
                    return true;
                }
                board[x][y] = '.';
                bitUnset(valid, i, x, y);
            }
            return false;
        }
        return backtrack(board, valid, 1 + level);
    }

    bool bitCheck(vector<int>& bitmap, int idx, int x, int y) {
        int mask = 0x1 << x;
        mask |= 0x1 << (9 + y);
        mask |= 0x1 << (18 + x / 3 * 3 + y / 3);
        return bitmap[idx] & mask;
    }

    void bitSet(vector<int>& bitmap, int idx, int x, int y) {
        int mask = 0x1 << x;
        mask |= 0x1 << (9 + y);
        mask |= 0x1 << (18 + x / 3 * 3 + y / 3);
        bitmap[idx] |= mask;
    }

    void bitUnset(vector<int>& bitmap, int idx, int x, int y) {
        int mask = 0x1 << x;
        mask |= 0x1 << (9 + y);
        mask |= 0x1 << (18 + x / 3 * 3 + y / 3);
        bitmap[idx] &= ~mask;
    }
};
// @lc code=end
