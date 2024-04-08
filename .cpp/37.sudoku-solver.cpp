/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
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
