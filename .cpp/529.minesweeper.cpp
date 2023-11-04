/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
// 1. DFS
// 2023-10-30 submission
// 54/54 cases passed
// Runtime: 18 ms, faster than 50.56% of cpp online submissions.
// Memory Usage: 12.7 MB, less than 44.64% of cpp online submissions.
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0];
        int col = click[1];

        if (board[row][col] == 'M') {
            // Clicked on a mine, game over
            board[row][col] = 'X';
        }
        else {
            // Perform DFS to reveal empty squares
            dfs(board, row, col);
        }

        return board;
    }

private:
    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            board[row][col] != 'E') {
            return;
        }

        // Count the number of adjacent mines
        int mineCount = 0;
        int directions[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                                {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        for (int i = 0; i < 8; ++i) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size() &&
                board[newRow][newCol] == 'M') {
                mineCount++;
            }
        }

        if (mineCount > 0) {
            // If there are adjacent mines, update the current square with the count
            board[row][col] = '0' + mineCount;
        }
        else {
            // If no adjacent mines, mark it as 'B' and recursively explore neighbors
            board[row][col] = 'B';
            for (int i = 0; i < 8; ++i) {
                int newRow = row + directions[i][0];
                int newCol = col + directions[i][1];
                dfs(board, newRow, newCol);
            }
        }
    }
};
// @lc code=end
