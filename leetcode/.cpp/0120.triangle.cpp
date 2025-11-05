/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
// 1. 动态规划-自顶向下
// 2025-02-14 submission
// 45/45 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 13.2 MB, less than 46.93% of cpp online submissions.
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; j++) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划-自底向上
// 2022-07-30 submission
// 44/44 cases passed
// Runtime: 10 ms, faster than 52.36% of cpp online submissions.
// Memory Usage: 8.6 MB, less than 89.2% of cpp online submissions.
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back().begin(), triangle.back().end());
        for (int k = dp.size() - 2; k >= 0; k--) {
            for (int i = 0; i <= k; i++) {
                dp[i] = min(dp[i], dp[i + 1]) + triangle[k][i];
            }
        }
        return dp[0];
    }
};
// @lc code=end
