/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (52.35%)
 * Likes:    7678
 * Dislikes: 113
 * Total Accepted:    429.1K
 * Total Submissions: 819.7K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an m x n integers matrix, return the length of the longest increasing
 * path in matrix.
 *
 * From each cell, you can either move in four directions: left, right, up, or
 * down. You may not move diagonally or move outside the boundary (i.e.,
 * wrap-around is not allowed).
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [[1]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * 0 <= matrix[i][j] <= 2^31 - 1
 *
 *
 */

// @lc code=start
// 2023-01-30 submission
// 138/138 cases passed
// Runtime: 181 ms, faster than 18.23% of C++ online submissions.
// Memory Usage: 41.9 MB, less than 8.17% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 1, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j]) return dp[i][j];
        int mx = 1, m = matrix.size(), n = matrix[0].size();
        for (vector<int> dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
            mx = max(mx, 1 + dfs(matrix, dp, x, y));
        }
        dp[i][j] = mx;
        return mx;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-30 submission
// 138/138 cases passed
// Runtime: 2735 ms, faster than 5.02% of C++ online submissions.
// Memory Usage: 547.4 MB, less than 5.05% of C++ online submissions.
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 1;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j ) {
                if (dp[i][j] > 0) continue;
                queue<vector<int>> q;
                q.push({i, j});
                int cnt = 1;
                while (!q.empty()) {
                    ++cnt;
                    int len = q.size();
                    for (int k = 0; k < len; ++k) {
                        auto t = q.front(); q.pop();
                        for (vector<int> dir : dirs) {
                            int x = t[0] + dir[0], y = t[1] + dir[1];
                            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[t[0]][t[1]] || cnt <= dp[x][y]) continue;
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