/*
 * @lc app=leetcode id=723 lang=cpp
 *
 * [723] Candy Crush
 */

// @lc code=start
// 1. 模拟
class Solution {
private:
    bool crush(vector<vector<int>> &board) {
        int m = board.size(), n = board[0].size();

        // scan row by row to find the candy to crush
        for (int k = 0; k < m; ++k) {
            for (int i = 0; i < n;) {
                int j = i;
                while (j < n && abs(board[k][j]) == abs(board[k][i])) {
                    ++j;
                }
                if (j - i >= 3) {
                    for (int l = i; l < j; ++l) {
                        board[k][l] = -abs(board[k][l]);
                    }
                }
                i = j;
            }
        }

        // scan column by column to find the candy to crush
        for (int k = 0; k < n; ++k) {
            for (int i = m - 1; i >= 0;) {
                int j = i;
                while (j >= 0 && abs(board[j][k]) == abs(board[i][k])) {
                    --j;
                }
                if (i - j >= 3) {
                    for (int l = i; l > j; --l) {
                        board[l][k] = -abs(board[l][k]);
                    }
                }
                i = j;
            }
        }

        // drop the candy
        int is_crush = false;
        for (int j = 0; j < n; ++j) {
            int i = m - 1;
            for (int k = m - 1; k >= 0; --k) {
                if (board[k][j] > 0) {
                    board[i--][j] = board[k][j];
                }
                else if (board[k][j] < 0) {
                    is_crush = true;
                }
                else {
                    break;
                }
            }
            while (i >= 0) {
                board[i--][j] = 0;
            }
        }

        return is_crush;
    }

public:
    vector<vector<int>> candyCrush(vector<vector<int>> &board) {
        while (crush(board))
            ;
        return board;
    }
};
// @lc code=end
