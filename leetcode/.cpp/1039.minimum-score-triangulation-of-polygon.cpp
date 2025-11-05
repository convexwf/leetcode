/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */

// @lc code=start
// 1. 记忆化搜索
// 2025-01-15 submission
// 94/94 cases passed
// Runtime: 3 ms, faster than 60.61% of cpp online submissions.
// Memory Usage: 11.2 MB, less than 36.56% of cpp online submissions.
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(0, n - 1, values, memo);
    }

    int dfs(int i, int j, vector<int>& values, vector<vector<int>>& memo) {
        if (j - i < 2) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int res = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
            res = min(res, dfs(i, k, values, memo) + dfs(k, j, values, memo) +
                               values[i] * values[j] * values[k]);
        }
        memo[i][j] = res;
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划
// 2025-01-15 submission
// 94/94 cases passed
// Runtime: 2 ms, faster than 69.57% of cpp online submissions.
// Memory Usage: 11.4 MB, less than 13.99% of cpp online submissions.
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len < n; ++len) {
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] =
                        min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end
