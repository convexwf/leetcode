/*
 * @lc app=leetcode id=903 lang=cpp
 *
 * [903] Valid Permutations for DI Sequence
 */

// @lc code=start
// 1. 动态规划
// 2025-06-08 submission
// 83/83 cases passed
// Runtime: 23 ms, faster than 59.16% of cpp online submissions.
// Memory Usage: 9.8 MB, less than 53.52% of cpp online submissions.
class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.size(), M = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        dp[0][0] = 1; // base case: one way to arrange an empty sequence
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (S[i - 1] == 'I') {
                    for (int k = j; k <= i - 1; ++k) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % M;
                    }
                }
                else {
                    for (int k = 0; k < j; ++k) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % M;
                    }
                }
            }
        }
        int result = 0;
        for (int j = 0; j <= n; ++j) {
            result = (result + dp[n][j]) % M;
        }
        return result;
    }
};
// @lc code=end
