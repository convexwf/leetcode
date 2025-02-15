/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
// 1. 动态规划
// 2023-05-18 submission
// 72/72 cases passed
// Runtime: 236 ms, faster than 80.16% of cpp online submissions.
// Memory Usage: 9.8 MB, less than 78.7% of cpp online submissions.
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const string& str : strs) {
            int zero = count(str.begin(), str.end(), '0');
            int one = str.size() - zeros;
            for (int i = m; i >= zero; --i) {
                for (int j = n; j >= one; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

// @lc code=start
// 2. 记忆化搜索
// 2023-05-18 submission
// 72/72 cases passed
// Runtime: 363 ms, faster than 40.98% of cpp online submissions.
// Memory Usage: 102.2 MB, less than 26.99% of cpp online submissions.
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> memo(strs.size(),
                                         vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dfs(strs, 0, m, n, memo);
    }

    int dfs(vector<string>& strs, int i, int zeros, int ones, vector<vector<vector<int>>>& memo) {
        if (i == strs.size()) return 0;
        if (memo[i][zeros][ones] != -1) {
            return memo[i][zeros][ones];
        }
        int cntZero = count(strs[i].begin(), strs[i].end(), '0');
        int cntOne = strs[i].size() - cntZero;
        int take = 0, notTake = 0;
        if (cntZero <= zeros && cntOne <= ones) {
            take = dfs(strs, i + 1, zeros - cntZero, ones - cntOne, memo) + 1;
        }
        notTake = dfs(strs, i + 1, zeros, ones, memo);
        memo[i][zeros][ones] = max(take, notTake);
        return memo[i][zeros][ones];
    }
};
// @lc code=end
