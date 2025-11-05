/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
// 1. 记忆化搜索+分类讨论
// 2023-12-21 submission
// 64/64 cases passed
// Runtime: 25 ms, faster than 12.44% of cpp online submissions.
// Memory Usage: 14.7 MB, less than 12.68% of cpp online submissions.
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -2));
        vector<int> ans(n, -1);
        for (int j = 0; j < n; ++j) {
            ans[j] = dfs(0, j, grid, memo);
        }
        return ans;
    }

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        int m = grid.size(), n = grid[0].size();
        if (i == m) {
            return j;
        }
        if (memo[i][j] != -2) {
            return memo[i][j];
        }
        if (j == 0 && grid[i][j] == -1) {
            return memo[i][j] = -1;
        }
        if (j == n - 1 && grid[i][j] == 1) {
            return memo[i][j] = -1;
        }
        if (grid[i][j] == 1 && grid[i][j + 1] == -1) {
            return memo[i][j] = -1;
        }
        if (grid[i][j] == -1 && grid[i][j - 1] == 1) {
            return memo[i][j] = -1;
        }
        return memo[i][j] = dfs(i + 1, j + grid[i][j], grid, memo);
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划
// 2023-12-21 submission
// 64/64 cases passed
// Runtime: 19 ms, faster than 63.38% of cpp online submissions.
// Memory Usage: 14.5 MB, less than 25.12% of cpp online submissions.
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n, -1));
        for (int j = 0; j < n; ++j) {
            dp[m][j] = j;
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if ((j == 0 && grid[i][j] == -1) || (j == n - 1 && grid[i][j] == 1)) {
                    dp[i][j] = -1;
                }
                else if (grid[i][j] == 1 && grid[i][j + 1] == -1) {
                    dp[i][j] = -1;
                }
                else if (grid[i][j] == -1 && grid[i][j - 1] == 1) {
                    dp[i][j] = -1;
                }
                else {
                    dp[i][j] = dp[i + 1][j + grid[i][j]];
                }
            }
        }
        vector<int> ans(dp[0].begin(), dp[0].end());
        return ans;
    }
};
// @lc code=end
