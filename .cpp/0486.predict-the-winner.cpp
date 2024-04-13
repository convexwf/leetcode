/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
// 1. 递归+记忆化搜索
// 2023-06-01 submission
// 62/62 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.7 MB, less than 22.38% of cpp online submissions.
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MIN));
        return dfs(nums, 0, n - 1, memo) >= 0;
    }

    int dfs(vector<int>& nums, int i, int j, vector<vector<int>>& memo) {
        if (i == j) return nums[i];
        if (memo[i][j] != INT_MIN) return memo[i][j];
        int left = nums[i] - dfs(nums, i + 1, j, memo);
        int right = nums[j] - dfs(nums, i, j - 1, memo);
        memo[i][j] = max(left, right);
        return memo[i][j];
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划+minmax
// 2023-06-01 submission
// 62/62 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.8 MB, less than 22.38% of cpp online submissions.
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = 0; len < n; ++len) {
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                if (i == j) {
                    dp[i][j] = nums[i];
                }
                else {
                    dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
// @lc code=end