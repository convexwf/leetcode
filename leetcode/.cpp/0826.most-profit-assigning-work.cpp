/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
// 1. 动态规划
// 2025-06-04 submission
// 60/60 cases passed
// Runtime: 12 ms, faster than 61.73% of cpp online submissions.
// Memory Usage: 50.3 MB, less than 6.23% of cpp online submissions.
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int res = 0, n = profit.size();
        int maxDifficulty = *max_element(difficulty.begin(), difficulty.end());
        int maxAbility = *max_element(worker.begin(), worker.end());
        vector<int> dp(max(maxDifficulty, maxAbility) + 1, 0);
        for (int i = 0; i < n; ++i) {
            dp[difficulty[i]] = max(dp[difficulty[i]], profit[i]);
        }
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = max(dp[i], dp[i - 1]);
        }
        for (int ability : worker) {
            res += dp[ability];
        }
        return res;
    }
};
// @lc code=end
