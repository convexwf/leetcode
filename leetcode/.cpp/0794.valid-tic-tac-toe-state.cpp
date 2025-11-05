/*
 * @lc app=leetcode id=794 lang=cpp
 *
 * [794] Valid Tic-Tac-Toe State
 */

// @lc code=start
// 1. 分类讨论
// 2023-11-06 submission
// 111/111 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.8 MB, less than 26.9% of cpp online submissions.
class Solution {
public:
    bool win(vector<string>& board, const char& c) {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c) {
                return true;
            }
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c) {
                return true;
            }
        }
        if (board[0][0] == c && board[1][1] == c && board[2][2] == c) {
            return true;
        }
        if (board[0][2] == c && board[1][1] == c && board[2][0] == c) {
            return true;
        }
        return false;
    }

    bool validTicTacToe(vector<string>& board) {
        int x = 0, o = 0;
        for (string& row : board) {
            for (char& c : row) {
                if (c == 'X') {
                    ++x;
                }
                else if (c == 'O') {
                    ++o;
                }
            }
        }
        if (o > x || x - o > 1) {
            return false;
        }
        if (win(board, 'X') && x - o != 1) {
            return false;
        }
        if (win(board, 'O') && x != o) {
            return false;
        }
        return true;
    }
};
// @lc code=end
