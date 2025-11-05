/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
// 1. 前缀和+记忆化搜索
// 2025-03-25 submission
// 92/92 cases passed
// Runtime: 4 ms, faster than 93.05% of cpp online submissions.
// Memory Usage: 14.9 MB, less than 45.31% of cpp online submissions.
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> sum(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            sum[i] = sum[i + 1] + piles[i];
        }
        vector<vector<int>> memo(n, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int i, int m) -> int {
            if (i == n) {
                return 0;
            }
            if (i + 2 * m >= n) {
                return sum[i];
            }
            if (memo[i][m] != -1) {
                return memo[i][m];
            }
            int res = 0;
            for (int x = 1; x <= 2 * m; ++x) {
                res = max(res, sum[i] - dfs(i + x, max(m, x)));
            }
            return memo[i][m] = res;
        };
        return dfs(0, 1);
    }
};
// @lc code=end
