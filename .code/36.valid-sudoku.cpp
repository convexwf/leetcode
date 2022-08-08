/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (55.98%)
 * Likes:    5803
 * Dislikes: 764
 * Total Accepted:    810.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * 
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 * without repetition.
 * 
 * 
 * Note:
 * 
 * 
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = 
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = 
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit 1-9 or '.'.
 * 
 * 
 */

// @lc code=start
// 2022-08-07 submission
// 507/507 cases passed
// Runtime: 15 ms, faster than 98.66% of C++ online submissions.
// Memory Usage: 18.1 MB, less than 74.07% of C++ online submissions.
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> valid(9, 0);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (bitCheck(valid, board[i][j] - '0' - 1, i, j))
                        return false;
                    bitSet(valid, board[i][j] - '0' - 1, i, j);
                }
            }
        }
        return true;
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
};
// @lc code=end

// @lc code=start
// 2022-08-07 submission
// 507/507 cases passed
// Runtime: 41 ms, faster than 41.59% of C++ online submissions.
// Memory Usage: 20.1 MB, less than 36.02% of C++ online submissions.
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> table;
        for(int i = 0 ; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    ostringstream s_row, s_col, s_block;
                    s_row << i << "(" << board[i][j] << ")";
                    s_col << "(" << board[i][j] << ")" << j;
                    s_block << i/3 << "(" << board[i][j] << ")" << j/3;
                    if(!table.insert(s_row.str()).second || 
                       !table.insert(s_col.str()).second || 
                       !table.insert(s_block.str()).second)
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end