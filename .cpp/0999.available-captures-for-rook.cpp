/*
 * @lc app=leetcode id=999 lang=cpp
 *
 * [999] Available Captures for Rook
 */

// @lc code=start
// 1. DFS
// 2023-08-13 submission
// 24/24 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.9 MB, less than 7.2% of cpp online submissions.
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x0 = 0, y0 = 0, res = 0;
        vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    x0 = i;
                    y0 = j;
                    break;
                }
            }
        }
        for (auto& dir : dirs) {
            int x = x0 + dir[0], y = y0 + dir[1];
            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (board[x][y] == 'p') ++res;
                if (board[x][y] != '.') break;
                x += dir[0];
                y += dir[1];
            }
        }
        return res;
    }
};
// @lc code=end
