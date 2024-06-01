/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
// 1. DFS
// 2023-02-09 submission
// 87/87 cases passed
// Runtime: 189 ms, faster than 90.99% of cpp online submissions.
// Memory Usage: 9.4 MB, less than 97.12% of cpp online submissions.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int u) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[u]) {
            return false;
        }
        if (u == word.size() - 1) {
            return true;
        }
        char temp = board[x][y];
        board[x][y] = '.';
        bool res = dfs(board, word, x + 1, y, u + 1) || dfs(board, word, x - 1, y, u + 1) ||
                   dfs(board, word, x, y + 1, u + 1) || dfs(board, word, x, y - 1, u + 1);
        board[x][y] = temp;
        return res;
    }
};
// @lc code=end
