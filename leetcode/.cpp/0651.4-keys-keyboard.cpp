/*
 * @lc app=leetcode id=651 lang=cpp
 *
 * [651] 4 Keys Keyboard
 */

// @lc code=start
// 1. 动态规划
class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 2; j < i; ++j) {
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }
        }
        return dp[n];
    }
};
// @lc code=end
