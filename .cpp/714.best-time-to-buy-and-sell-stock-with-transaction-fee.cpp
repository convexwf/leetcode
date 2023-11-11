/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
// 1. 动态规划
// 2023-11-08 submission
// 44/44 cases passed
// Runtime: 162 ms, faster than 53.8% of cpp online submissions.
// Memory Usage: 91.2 MB, less than 46.68% of cpp online submissions.
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
// @lc code=end

// @lc code=start
// 2. 记忆化搜索
// 2023-11-08 submission
// 44/44 cases passed
// Runtime: 199 ms, faster than 9.38% of cpp online submissions.
// Memory Usage: 105.2 MB, less than 5.21% of cpp online submissions.
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return dfs(prices, fee, 0, 0, memo);
    }

    int dfs(vector<int>& prices, int fee, int index, int status, vector<vector<int>>& memo) {
        if (index == prices.size()) {
            return 0;
        }
        if (memo[index][status] != -1) {
            return memo[index][status];
        }
        int a = 0, b = 0, c = 0;
        a = dfs(prices, fee, index + 1, status, memo);
        if (status == 0) {
            b = dfs(prices, fee, index + 1, 1, memo) - prices[index];
        }
        else {
            c = dfs(prices, fee, index + 1, 0, memo) + prices[index] - fee;
        }
        return memo[index][status] = max({a, b, c});
    }
};
// @lc code=end
