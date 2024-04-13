/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
// 2020-09-20 submission
// 58/58 cases passed
// Runtime: 27 ms, faster than 61.01% of cpp online submissions.
// Memory Usage: 10 MB, less than 82.55% of cpp online submissions.
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int res = 0;
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> mask(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    DFS(board, mask, i, j);
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!mask[i][j]) board[i][j] = 'X';
            }
        }
    }

    void DFS(vector<vector<char>>& board, vector<vector<bool>>& mask, int i, int j) {
        if (board[i][j] != 'O' || mask[i][j]) return;
        mask[i][j] = true;
        if (i > 0) DFS(board, mask, i - 1, j);
        if (i < board.size() - 1) DFS(board, mask, i + 1, j);
        if (j > 0) DFS(board, mask, i, j - 1);
        if (j < board[0].size() - 1) DFS(board, mask, i, j + 1);
    }
};
// @lc code=end

// @lc code=start
// 2022-11-17 submission
// 58/58 cases passed
// Runtime: 58 ms, faster than 7.39% of cpp online submissions.
// Memory Usage: 13.1 MB, less than 12.78% of cpp online submissions.
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (board[i][j] == 'O') dfs(board, i, j);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dir{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        board[x][y] = '$';
        for (int i = 0; i < dir.size(); ++i) {
            int dx = x + dir[i][0], dy = y + dir[i][1];
            if (dx >= 0 && dx < m && dy > 0 && dy < n && board[dx][dy] == 'O') {
                dfs(board, dx, dy);
            }
        }
    }
};
// @lc code=end

// @lc code=start
// 2022-11-17 submission
// 58/58 cases passed
// Runtime: 16 ms, faster than 84.21% of cpp online submissions.
// Memory Usage: 10.4 MB, less than 39.2% of cpp online submissions.
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != 0 && i != m - 1 && j != 0 && j != n - 1) continue;
                if (board[i][j] != 'O') continue;
                board[i][j] = '$';
                queue<int> q{{i * n + j}};
                while (!q.empty()) {
                    int t = q.front(), x = t / n, y = t % n;
                    q.pop();
                    if (x >= 1 && board[x - 1][y] == 'O') {
                        board[x - 1][y] = '$';
                        q.push(t - n);
                    }
                    if (x < m - 1 && board[x + 1][y] == 'O') {
                        board[x + 1][y] = '$';
                        q.push(t + n);
                    }
                    if (y >= 1 && board[x][y - 1] == 'O') {
                        board[x][y - 1] = '$';
                        q.push(t - 1);
                    }
                    if (y < n - 1 && board[x][y + 1] == 'O') {
                        board[x][y + 1] = '$';
                        q.push(t + 1);
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
};
// @lc code=end
