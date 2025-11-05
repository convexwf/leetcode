/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
// 1. 位操作+原地标记
// 2022-08-26 submission
// 22/22 cases passed
// Runtime: 2 ms, faster than 58.11% of cpp online submissions.
// Memory Usage: 7 MB, less than 20.25% of cpp online submissions.
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                    {0, 1},   {1, -1}, {1, 0},  {1, 1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dirs[k][0], y = j + dirs[k][1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        live += board[x][y] & 1;
                    }
                }
                // If the cell is live, it will be live in the next generation
                // if and only if it has 2 or 3 live neighbors.
                if ((board[i][j] & 1) == 1) {
                    if (live == 2 || live == 3) {
                        board[i][j] |= 0b10;
                    }
                }
                // If the cell is dead, it will be live in the next generation
                // if and only if it has exactly 3 live neighbors.
                else {
                    if (live == 3) {
                        board[i][j] |= 0b10;
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
// @lc code=end
