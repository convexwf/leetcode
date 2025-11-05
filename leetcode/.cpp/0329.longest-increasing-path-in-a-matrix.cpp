/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
// 1. dfs+记忆数组
// 2023-01-30 submission
// 138/138 cases passed
// Runtime: 181 ms, faster than 18.23% of cpp online submissions.
// Memory Usage: 41.9 MB, less than 8.17% of cpp online submissions.
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> memo(m, vector<int>(n, 0));
        function<int(int, int)> dfs = [&](int x, int y) {
            if (memo[x][y] != 0) {
                return memo[x][y];
            }
            int res = 1;
            for (vector<int>& dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y]) {
                    res = max(res, 1 + dfs(nx, ny));
                }
            }
            memo[x][y] = res;
            return res;
        };
        int longest = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                longest = max(longest, dfs(i, j));
            }
        }
        return longest;
    }
};
// @lc code=end

// @lc code=start
// 2. bfs+记忆数组
// 2023-01-30 submission
// 138/138 cases passed
// Runtime: 2735 ms, faster than 5.02% of cpp online submissions.
// Memory Usage: 547.4 MB, less than 5.05% of cpp online submissions.
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 1;
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] > 0) continue;
                queue<vector<int>> q;
                q.push({i, j});
                int cnt = 1;
                while (!q.empty()) {
                    ++cnt;
                    int len = q.size();
                    for (int k = 0; k < len; ++k) {
                        auto t = q.front();
                        q.pop();
                        for (vector<int> dir : dirs) {
                            int x = t[0] + dir[0], y = t[1] + dir[1];
                            if (x < 0 || x >= m || y < 0 || y >= n ||
                                matrix[x][y] <= matrix[t[0]][t[1]] || cnt <= dp[x][y])
                                continue;
                            dp[x][y] = cnt;
                            res = max(res, cnt);
                            q.push({x, y});
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
