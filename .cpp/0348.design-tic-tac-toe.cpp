/*
 * @lc app=leetcode id=348 lang=cpp
 *
 * [348] Design Tic-Tac-Toe
 */

// @lc code=start
// 1. 计数
class TicTacToe {
private:
    vector<vector<int>> player_stat;
    int n;

public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : n(n), player_stat(2, vector<int>(2 * n + 2, 0)) {
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        player_stat[player - 1][row]++;
        player_stat[player - 1][n + col]++;
        if (row == col) {
            player_stat[player - 1][2 * n]++;
        }
        if (row + col == n - 1) {
            player_stat[player - 1][2 * n + 1]++;
        }
        if (player_stat[player - 1][row] == n || player_stat[player - 1][n + col] == n ||
            player_stat[player - 1][2 * n] == n || player_stat[player - 1][2 * n + 1] == n) {
            return player;
        }
        return 0;
    }
};
// @lc code=end
