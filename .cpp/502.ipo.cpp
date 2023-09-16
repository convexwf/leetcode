/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = w;
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= min(i, k); ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0 && dp[i - 1][j - 1] >= capital[i - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + profits[i - 1]);
                }
                res = max(res, dp[i][j]);
                cout << "i: " << i << " j: " << j << " dp: " << dp[i][j] << endl;
            }
        }
        return res;
    }
};
// @lc code=end
