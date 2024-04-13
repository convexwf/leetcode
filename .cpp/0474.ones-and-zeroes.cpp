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
// 2023-05-18 submission
// 72/72 cases passed
// Runtime: 688 ms, faster than 13.42% of cpp online submissions.
// Memory Usage: 103.2 MB, less than 9.02% of cpp online submissions.
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int L = strs.size();
        // 定义weight数组，记录每个字符串中 0 和 1 的数量
        vector<vector<int>> weight(L, vector<int>(2));
        for (int i = 0; i < L; i++) {
            string str = strs[i];
            weight[i][0] = count(str.begin(), str.end(), '0');
            weight[i][1] = str.size() - weight[i][0];
        }
        // 定义dp数组，记录是否可以组成最多的字符串
        vector<vector<vector<int>>> dp(L + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 1; i <= L; i++) {                     // 第i个物品(序号从1开始)
            for (int mFree = 0; mFree <= m; mFree++) {     // 背包剩余x容量
                for (int nFree = 0; nFree <= n; nFree++) { // 背包剩余y容量
                    // 当前物品的重量大于当前背包可用的空间，则不能装入当前物品
                    if (weight[i][0] > mFree || weight[i][1] > nFree) {
                        dp[i][mFree][nFree] = dp[i - 1][mFree][nFree]; // 直接沿用前面的最优解
                    }
                    else {
                        dp[i][mFree][nFree] = max( // 能装入当前物品，比较两种情况：加入当前物品和不加入当前物品哪个更优
                            dp[i - 1][mFree - weight[i][0]][nFree - weight[i][1]] + 1, dp[i - 1][mFree][nFree]);
                    }
                }
            }
        }
        return dp[L][m][n];
    }
};
// @lc code=end

// @lc code=start
// 3. 记忆化搜索
// 2023-05-18 submission
// 72/72 cases passed
// Runtime: 363 ms, faster than 40.98% of cpp online submissions.
// Memory Usage: 102.2 MB, less than 26.99% of cpp online submissions.
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> memo(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dfs(strs, 0, m, n, memo);
    }

    int dfs(vector<string>& strs, int i, int zeros, int ones, vector<vector<vector<int>>>& memo) {
        if (i == strs.size()) return 0;
        if (memo[i][zeros][ones] != -1) return memo[i][zeros][ones];
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