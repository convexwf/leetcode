/*
 * @lc app=leetcode id=361 lang=cpp
 *
 * [361] Bomb Enemy
 */

// @lc code=start
// 1. 循环遍历计数
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'W') cnt = 0;
                else if (grid[i][j] == 'E') cnt++;
                else dp[i][j] += cnt;
            }
            cnt = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 'W') cnt = 0;
                else if (grid[i][j] == 'E') cnt++;
                else dp[i][j] += cnt;
            }
        }
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 'W') cnt = 0;
                else if (grid[i][j] == 'E') cnt++;
                else dp[i][j] += cnt;
            }
            cnt = 0;
            for (int i = m - 1; i >= 0; i--) {
                if (grid[i][j] == 'W') cnt = 0;
                else if (grid[i][j] == 'E') cnt++;
                else dp[i][j] += cnt;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end
