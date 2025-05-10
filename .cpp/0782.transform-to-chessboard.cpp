/*
 * @lc app=leetcode id=782 lang=cpp
 *
 * [782] Transform to Chessboard
 */

// @lc code=start
// 1. 规律观察
// 2025-04-14 submission
// 127/127 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 13.7 MB, less than 51.49% of cpp online submissions.
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size(), rowSum = 0, colSum = 0, rowDiff = 0, colDiff = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) {
                    return -1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            rowSum += board[0][i];
            colSum += board[i][0];
            rowDiff += (board[i][0] == i % 2);
            colDiff += (board[0][i] == i % 2);
        }
        if (n / 2 > rowSum || rowSum > (n + 1) / 2) return -1;
        if (n / 2 > colSum || colSum > (n + 1) / 2) return -1;
        if (n % 2) {
            if (rowDiff % 2) rowDiff = n - rowDiff;
            if (colDiff % 2) colDiff = n - colDiff;
        }
        else {
            rowDiff = min(n - rowDiff, rowDiff);
            colDiff = min(n - colDiff, colDiff);
        }
        return (rowDiff + colDiff) / 2;
    }
};
// @lc code=end
