/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 */

// @lc code=start
// 1. 动态规划
// 2023-06-30 submission
// 51/51 cases passed
// Runtime: 21 ms, faster than 67.13% of cpp online submissions.
// Memory Usage:  MB, less than 59.92% of cpp online submissions.
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<vector<double>> dp(n + 1, vector<double>(K + 1, 0));
        vector<double> sum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + A[i - 1];
            dp[i][1] = sum[i] / i;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 2; j <= min(i, K); ++j) {
                for (int k = j - 1; k < i; ++k) {
                    dp[i][j] = max(dp[i][j], dp[k][j - 1] + (sum[i] - sum[k]) / (i - k));
                }
            }
        }
        return dp[n][K];
    }
};
// @lc code=end

// @lc code=start
// 2. 递归+记忆化搜索
// 2023-06-30 submission
// 51/51 cases passed
// Runtime: 38 ms, faster than 26.05% of cpp online submissions.
// Memory Usage: 13.3 MB, less than 13.43% of cpp online submissions.
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<vector<double>> memo(101, vector<double>(101));
        double cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += A[i];
            memo[i + 1][1] = cur / (i + 1);
        }
        return dfs(A, K, n, memo);
    }
    double dfs(vector<int>& A, int k, int j, vector<vector<double>>& memo) {
        if (memo[j][k] > 0) return memo[j][k];
        double cur = 0;
        for (int i = j - 1; i > 0; --i) {
            cur += A[i];
            memo[j][k] = max(memo[j][k], dfs(A, k - 1, i, memo) + cur / (j - i));
        }
        return memo[j][k];
    }
};
// @lc code=end