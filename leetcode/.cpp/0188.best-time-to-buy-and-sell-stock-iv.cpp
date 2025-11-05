/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
// 1. 动态规划
// 2024-09-12 submission
// 210/210 cases passed
// Runtime: 46 ms, faster than 12.76% of cpp online submissions.
// Memory Usage:  MB, less than 8.83% of cpp online submissions.
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        if (k > n / 2) {
            return maxProfit(prices);
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        for (int i = 0; i <= k; i++) {
            dp[0][i][1] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][k][0];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (int i = 0; i < n; i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
};
// @lc code=end

// @lc code=start
// 2020-07-24 submission
// 210/210 cases passed
// Runtime: 9 ms, faster than 90.33% of cpp online submissions.
// Memory Usage: 10.9 MB, less than 84.39% of cpp online submissions.
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        if (k > prices.size()) return maxProfit_largetrades(prices);
        vector<int> local(k + 1, 0), global(k + 1, 0);
        for (int day = 1; day < prices.size(); day++) {
            int diff = prices[day] - prices[day - 1];
            for (int j = k; j >= 1; j--) { // 为什么要 j 从 k 遍历到 1，而不是 1 遍历到 k
                local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
                global[j] = max(local[j], global[j]);
                // cout << "day:" << day << " j:" << j << " local:"<<local[j] << " global:" <<
                // global[j] << endl;
            }
        }
        return global[k];
    }

    int maxProfit_largetrades(vector<int>& prices) {
        int maxValue = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) maxValue += (prices[i] - prices[i - 1]);
        }
        return maxValue;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划-空间优化
// 2024-09-12 submission
// 210/210 cases passed
// Runtime: 3 ms, faster than 95.2% of cpp online submissions.
// Memory Usage: 13.6 MB, less than 81.65% of cpp online submissions.
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        if (k > n / 2) {
            return maxProfit(prices);
        }
        vector<vector<int>> dp(k + 1, vector<int>(2, 0));
        for (int i = 0; i <= k; ++i) {
            dp[i][1] = INT_MIN;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = k; j > 0; --j) {
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
                dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]);
            }
        }
        return dp[k][0];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
};
// @lc code=end
