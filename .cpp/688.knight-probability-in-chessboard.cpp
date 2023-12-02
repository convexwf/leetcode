/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
// 1. 动态规划
// 2023-11-27 submission
// 22/22 cases passed
// Runtime: 18 ms, faster than 43.79% of cpp online submissions.
// Memory Usage: 9.2 MB, less than 54.08% of cpp online submissions.
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, 1)));
        vector<vector<int>> directions = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                          {1, -2},  {1, 2},  {2, -1},  {2, 1}};
        for (int h = 1; h <= k; ++h) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp[i][j][h] = 0;
                    for (auto& direction : directions) {
                        int dx = direction[0], dy = direction[1];
                        if (i + dx >= 0 && i + dx < n && j + dy >= 0 && j + dy < n) {
                            dp[i][j][h] += dp[i + dx][j + dy][h - 1] / 8;
                        }
                    }
                }
            }
        }
        return dp[row][column][k];
    }
};
// @lc code=end

// @lc code=start
// 2. 记忆化搜索
// 2023-11-27 submission
// 22/22 cases passed
// Runtime: 19 ms, faster than 41.28% of cpp online submissions.
// Memory Usage: 9.1 MB, less than 54.08% of cpp online submissions.
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> memo(n, vector<vector<double>>(n, vector<double>(k + 1, 0)));
        return dfs(n, k, row, column, memo);
    }

    double dfs(int n, int k, int i, int j, vector<vector<vector<double>>>& memo) {
        if (i < 0 || i >= n || j < 0 || j >= n) return 0;
        if (k == 0) return 1;
        if (memo[i][j][k] != 0) return memo[i][j][k];
        for (auto& d : dirs) {
            memo[i][j][k] += dfs(n, k - 1, i + d[0], j + d[1], memo) / 8;
        }
        return memo[i][j][k];
    }

private:
    vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                {1, -2},  {1, 2},  {2, -1},  {2, 1}};
};
// @lc code=end
