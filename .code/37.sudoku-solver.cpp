/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (55.46%)
 * Likes:    5931
 * Dislikes: 167
 * Total Accepted:    378.4K
 * Total Submissions: 682.2K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * The '.' character indicates empty cells.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 * 
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 * 
 * 
 */

// @lc code=start
// 2022-08-07 submission
// 6/6 cases passed
// Runtime: 5 ms, faster than 97.74% of C++ online submissions.
// Memory Usage: 6.4 MB, less than 49.84% of C++ online submissions.
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

// @lc code=start
class Solution {
public:
    
};
// @lc code=end