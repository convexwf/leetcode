/*
 * @lc app=leetcode id=964 lang=cpp
 *
 * [964] Least Operators to Express Number
 */

// @lc code=start
class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        if (target == 0) return 0;
        if (target == 1) return 1;

        unordered_map<int, int> memo;
        return dfs(x, target, memo);
    }

    int dfs(int x, int target, unordered_map<int, int>& memo) {
        if (target < 0) return INT_MAX; // 不可能的情况
        if (target == 0) return 0;      // 完全匹配
        if (target == 1) return 1;      // 只需要一个操作

        if (memo.count(target)) return memo[target];

        int minOps = INT_MAX;

        // 尝试加法和减法
        for (int i = 1; i <= target / x + 1; ++i) {
            int addOps = i + dfs(x, target - i * x, memo);
            int subOps = i + dfs(x, target + i * x, memo);
            minOps = min({minOps, addOps, subOps});
        }

        // 尝试乘法
        for (int i = 2; i <= target / x + 1; ++i) {
            if (target % i == 0) {
                int mulOps = i - 1 + dfs(x, target / i, memo);
                minOps = min(minOps, mulOps);
            }
        }

        memo[target] = minOps;
        return minOps;
    }
};
// @lc code=end
