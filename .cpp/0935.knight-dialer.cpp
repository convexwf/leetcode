/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 */

// @lc code=start
// 1. 动态规划
// 2024-01-12 submission
// 121/121 cases passed
// Runtime: 153 ms, faster than 32.77% of cpp online submissions.
// Memory Usage: 37.9 MB, less than 31.68% of cpp online submissions.
class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> jump = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {3, 9, 0},
                                    {},     {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
        const int mod = 1e9 + 7;

        vector<vector<int>> dp(n, vector<int>(10, 0));
        for (int j = 0; j < 10; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k : jump[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                }
            }
        }
        int res = 0;
        for (int j = 0; j < 10; ++j) {
            res = (res + dp[n - 1][j]) % mod;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 数学方法-矩阵相乘
// 2024-12-24 submission
// 121/121 cases passed
// Runtime: 16 ms, faster than 95.08% of cpp online submissions.
// Memory Usage: 11.4 MB, less than 73.33% of cpp online submissions.
class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }

        const int MOD = 1e9 + 7;
        vector<vector<int>> transformation = {
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, // 0 -> 4, 6
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0}, // 1 -> 6, 8
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, // 2 -> 7, 9
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0}, // 3 -> 4, 8
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 1}, // 4 -> 3, 9, 0
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5 -> -
            {1, 1, 0, 0, 0, 0, 0, 1, 0, 0}, // 6 -> 1, 7, 0
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, // 7 -> 2, 6
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, // 8 -> 1, 3
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}  // 9 -> 2, 4
        };

        // matrix multiplication
        auto matrix_multiply = [&](vector<vector<int>>& a, vector<vector<int>>& b, int n) {
            vector<vector<int>> c(n, vector<int>(n, 0));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        c[i][j] = (c[i][j] + (long long)a[i][k] * b[k][j]) % MOD;
                    }
                }
            }
            return c;
        };

        // matrix fast power
        auto matrix_fast_power = [&](vector<vector<int>>& a, int exp, int n) {
            vector<vector<int>> res(n, vector<int>(n, 0));
            for (int i = 0; i < n; ++i) {
                res[i][i] = 1;
            }
            while (exp > 0) {
                if (exp & 1) {
                    res = matrix_multiply(res, a, n);
                }
                a = matrix_multiply(a, a, n);
                exp >>= 1;
            }
            return res;
        };

        vector<vector<int>> result_matrix = matrix_fast_power(transformation, n - 1, 10);
        int result = 0;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                result = (result + result_matrix[i][j]) % MOD;
            }
        }
        return result;
    }
};
// @lc code=end
