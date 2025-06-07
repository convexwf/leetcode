/*
 * @lc app=leetcode id=903 lang=cpp
 *
 * [903] Valid Permutations for DI Sequence
 */

// @lc code=start
// 1. 动态规划
// 2025-06-04 submission
// 83/83 cases passed
// Runtime: 3 ms, faster than 79.85% of cpp online submissions.
// Memory Usage: 9.8 MB, less than 58.96% of cpp online submissions.
class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.size(), M = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 0; i < n; ++i) {
            if (S[i] == 'I') {
                for (int j = 0, cur = 0; j < n - i; ++j) {
                    cur = (cur + dp[i][j]) % M;
                    dp[i + 1][j] = cur;
                }
            }
            else {
                for (int j = n - 1 - i, cur = 0; j >= 0; --j) {
                    cur = (cur + dp[i][j + 1]) % M;
                    dp[i + 1][j] = cur;
                }
            }
        }
        return dp[n][0];
    }
};
// @lc code=end
