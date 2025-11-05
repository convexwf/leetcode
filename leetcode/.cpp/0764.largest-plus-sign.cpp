/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
 */

// @lc code=start
// 1. 计数
// 2023-07-17 submission
// 56/56 cases passed
// Runtime: 324 ms, faster than 71.34% of cpp online submissions.
// Memory Usage: 89.3 MB, less than 39.02% of cpp online submissions.
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for (auto& mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }
        vector<vector<int>> left(n, vector<int>(n, 0));
        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> up(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                    up[i][j] = (i == 0 ? 0 : up[i - 1][j]) + 1;
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    right[i][j] = (j == n - 1 ? 0 : right[i][j + 1]) + 1;
                    down[i][j] = (i == n - 1 ? 0 : down[i + 1][j]) + 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, min({left[i][j], right[i][j], up[i][j], down[i][j]}));
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划+空间优化
// 2023-07-17 submission
// 56/56 cases passed
// Runtime: 233 ms, faster than 92.07% of cpp online submissions.
// Memory Usage: 31.8 MB, less than 88.41% of cpp online submissions.
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (auto& mine : mines) {
            dp[mine[0]][mine[1]] = 0;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0, k = n - 1, l = 0, r = 0, u = 0, d = 0; j < n; ++j, --k) {
                dp[i][j] = min(dp[i][j], l = (dp[i][j] == 0 ? 0 : l + 1));
                dp[i][k] = min(dp[i][k], r = (dp[i][k] == 0 ? 0 : r + 1));
                dp[j][i] = min(dp[j][i], u = (dp[j][i] == 0 ? 0 : u + 1));
                dp[k][i] = min(dp[k][i], d = (dp[k][i] == 0 ? 0 : d + 1));
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end
