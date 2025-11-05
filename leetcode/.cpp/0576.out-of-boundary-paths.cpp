/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
// 1. 动态规划
// 2023-05-18 submission
// 94/94 cases passed
// Runtime: 34 ms, faster than 12.04% of cpp online submissions.
// Memory Usage:  MB, less than 22.65% of cpp online submissions.
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1)));
        for (int k = 1; k <= maxMove; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int left = (j == 0) ? 1 : dp[i][j - 1][k - 1];
                    int right = (j == n - 1) ? 1 : dp[i][j + 1][k - 1];
                    int up = (i == 0) ? 1 : dp[i - 1][j][k - 1];
                    int down = (i == m - 1) ? 1 : dp[i + 1][j][k - 1];
                    dp[i][j][k] = ((left + right) % MOD + (up + down) % MOD) % MOD;
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
};
// @lc code=end

// @lc code=start
// 2. 记忆化搜索
// 2023-05-18 submission
// 94/94 cases passed
// Runtime: 7 ms, faster than 88.37% of cpp online submissions.
// Memory Usage: 9.5 MB, less than 45.31% of cpp online submissions.
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(maxMove + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        return dfs(startRow, startColumn, maxMove, m, n, memo);
    }

private:
    const int MOD = 1e9 + 7;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int dfs(int i, int j, int k, int m, int n, vector<vector<vector<int>>>& memo) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 1;
        }
        if (k == 0) {
            return 0;
        }
        if (memo[k][i][j] != -1) {
            return memo[k][i][j];
        }

        int count = 0;
        for (int d = 0; d < 4; ++d) {
            int ni = i + dx[d], nj = j + dy[d];
            count += dfs(ni, nj, k - 1, m, n, memo);
            count %= MOD;
        }
        memo[k][i][j] = count;
        return count;
    }
};
// @lc code=end
