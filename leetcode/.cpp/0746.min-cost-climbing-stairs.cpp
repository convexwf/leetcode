/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
// 1. 记忆化搜索
// 2024-11-07 submission
// 284/284 cases passed
// Runtime: 4 ms, faster than 7.64% of cpp online submissions.
// Memory Usage:  MB, less than 5.39% of cpp online submissions.
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);
        function<int(int)> dfs = [&](int i) {
            if (i >= n) return 0;
            if (memo[i] != -1) return memo[i];
            return memo[i] = cost[i] + min(dfs(i + 1), dfs(i + 2));
        };
        return min(dfs(0), dfs(1));
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划
// 2024-11-07 submission
// 284/284 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 16.8 MB, less than 53.49% of cpp online submissions.
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};
// @lc code=end
