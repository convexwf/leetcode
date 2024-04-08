/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
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
