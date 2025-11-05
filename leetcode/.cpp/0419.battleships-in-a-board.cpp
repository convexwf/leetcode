/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 */

// @lc code=start
// 1. 模拟
// 2023-05-25 submission
// 27/27 cases passed
// Runtime: 8 ms, faster than 76.75% of cpp online submissions.
// Memory Usage: 8.1 MB, less than 79.86% of cpp online submissions.
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    if (i > 0 && board[i - 1][j] == 'X') continue;
                    if (j > 0 && board[i][j - 1] == 'X') continue;
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end
