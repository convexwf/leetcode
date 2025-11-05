/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
// 1. 动态规划
// 2020-11-25 submission
// 189/189 cases passed
// Runtime: 141 ms, faster than 66.75% of cpp online submissions.
// Memory Usage: 14.5 MB, less than 55.71% of cpp online submissions.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin > i) continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
// @lc code=end

// @lc code=start
// 2. 记忆化搜索
// 2020-11-25 submission
// 189/189 cases passed
// Runtime: 213 ms, faster than 35.97% of cpp online submissions.
// Memory Usage: 15.5 MB, less than 39.04% of cpp online submissions.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, 0);
        return dfs(coins, amount, memo);
    }

    int dfs(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        if (memo[amount] != 0) {
            return memo[amount];
        }
        int res = INT_MAX;
        for (int j = 0; j < coins.size(); ++j) {
            int sub = dfs(coins, amount - coins[j], memo);
            if (sub == -1) continue;
            res = min(res, sub + 1);
        }
        memo[amount] = res == INT_MAX ? -1 : res;
        return memo[amount];
    }
};
// @lc code=end
