/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
// 1. 动态规划
// 2024-01-08 submission
// 74/74 cases passed
// Runtime: 12 ms, faster than 72.51% of cpp online submissions.
// Memory Usage: 13.4 MB, less than 33.17% of cpp online submissions.
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
