/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
// 1. dfs
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
                    dfs(board, mask, i, j);
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!mask[i][j]) board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& mask, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || mask[i][j] ||
            board[i][j] == 'X')
            return;
        mask[i][j] = true;
        dfs(board, mask, i - 1, j);
        dfs(board, mask, i + 1, j);
        dfs(board, mask, i, j - 1);
        dfs(board, mask, i, j + 1);
    }
};
// @lc code=end

// @lc code=start
// 2. dfs-空间优化
// 2024-07-03 submission
// 58/58 cases passed
// Runtime: 4 ms, faster than 96.71% of cpp online submissions.
// Memory Usage: 13.4 MB, less than 90.48% of cpp online submissions.
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    dfs(board, i, j);
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
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') return;
        board[x][y] = '$';
        dfs(board, x - 1, y);
        dfs(board, x + 1, y);
        dfs(board, x, y - 1);
        dfs(board, x, y + 1);
    }
};
// @lc code=end

// @lc code=start
// 3. bfs
// 2022-11-17 submission
// 58/58 cases passed
// Runtime: 16 ms, faster than 84.21% of cpp online submissions.
// Memory Usage: 10.4 MB, less than 39.2% of cpp online submissions.
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') q.push({i, 0});
            if (board[i][n - 1] == 'O') q.push({i, n - 1});
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') q.push({0, j});
            if (board[m - 1][j] == 'O') q.push({m - 1, j});
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') continue;
            board[x][y] = '$';
            q.push({x - 1, y});
            q.push({x + 1, y});
            q.push({x, y - 1});
            q.push({x, y + 1});
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

// @lc code=start
// 4. 并查集
// 2024-07-03 submission
// 58/58 cases passed
// Runtime: 17 ms, faster than 12.63% of cpp online submissions.
// Memory Usage: 13.8 MB, less than 57.72% of cpp online submissions.
class Solution {
private:
    int find(vector<int>& parent, int x) {
        if (x != parent[x]) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    void merge(vector<int>& parent, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if (rootX > rootY) {
            parent[rootY] = rootX;
        }
        else {
            parent[rootX] = rootY;
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        int dummy = m * n;
        vector<int> parent(dummy + 1, dummy);

        // connect the border 'O' to the dummy node
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (x != 0 && x != m - 1 && y != 0 && y != n - 1) {
                    parent[x * n + y] = x * n + y;
                }
            }
        }

        // merge the 'O' which are connected
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (board[x][y] == 'O') {
                    if (x > 0 && board[x - 1][y] == 'O') {
                        merge(parent, x * n + y, (x - 1) * n + y);
                    }
                    if (x < m - 1 && board[x + 1][y] == 'O') {
                        merge(parent, x * n + y, (x + 1) * n + y);
                    }
                    if (y > 0 && board[x][y - 1] == 'O') {
                        merge(parent, x * n + y, x * n + y - 1);
                    }
                    if (y < n - 1 && board[x][y + 1] == 'O') {
                        merge(parent, x * n + y, x * n + y + 1);
                    }
                }
            }
        }

        // flip the 'O' to 'X'
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (board[x][y] == 'O' && find(parent, x * n + y) != dummy) {
                    board[x][y] = 'X';
                }
            }
        }
    }
};
// @lc code=end
