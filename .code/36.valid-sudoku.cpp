/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
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