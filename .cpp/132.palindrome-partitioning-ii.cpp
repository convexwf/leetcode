/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
// 2023-02-27 submission
// 36/36 cases passed
// Runtime: 28 ms, faster than 92.06% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 45.56% of cpp online submissions.
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> judge(n, vector<bool>(n, false));
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = i + 1;
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (j + 2 > i || judge[j + 1][i - 1])) {
                    judge[j][i] = true;
                    dp[i + 1] = min(dp[j] + 1, dp[i + 1]);
                }
            }
        }
        return dp.back() - 1;
    }
};
// @lc code=end
