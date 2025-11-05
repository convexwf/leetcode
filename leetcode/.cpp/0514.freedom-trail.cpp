/*
 * @lc app=leetcode id=514 lang=cpp
 *
 * [514] Freedom Trail
 */

// @lc code=start
// 1. 动态规划
// 2025-02-08 submission
// 303/303 cases passed
// Runtime: 171 ms, faster than 14.91% of cpp online submissions.
// Memory Usage: 16.3 MB, less than 45.58% of cpp online submissions.
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(m + 1, vector<int>(n, INT_MAX));
        dp[m].assign(n, 0);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (ring[k] == key[i]) {
                        int diff = abs(j - k);
                        dp[i][j] = min(dp[i][j], dp[i + 1][k] + min(diff, n - diff));
                    }
                }
            }
        }
        return dp[0][0] + m;
    }
};
// @lc code=end

// @lc code=start
// 2. 记忆化搜索
// 2025-02-08 submission
// 303/303 cases passed
// Runtime: 27 ms, faster than 46.45% of cpp online submissions.
// Memory Usage: 17.3 MB, less than 30.33% of cpp online submissions.
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> memo(m + 1, vector<int>(n, INT_MAX));
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i == m) {
                return 0;
            }
            if (memo[i][j] != INT_MAX) {
                return memo[i][j];
            }
            for (int k = 0; k < n; ++k) {
                if (ring[k] == key[i]) {
                    int diff = abs(j - k);
                    memo[i][j] = min(memo[i][j], dfs(i + 1, k) + min(diff, n - diff));
                }
            }
            return memo[i][j];
        };
        return dfs(0, 0) + m;
    }
};
// @lc code=end
