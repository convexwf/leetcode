/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int64_t>> dp(n + 1, vector<int64_t>(m + 1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j] + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
                cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

// @lc code=start
// 2020-09-15 submission
// 65/65 cases passed
// Runtime: 27 ms, faster than 92.23% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 81.14% of cpp online submissions.
class Solution {
public:
    int numDistinct(string s, string t) {
        int c1 = s.length(), c2 = t.length();
        vector<long> dp(c1 + 1, 1); // why long type

        int last_valid = 0;
        for (int i = 1; i <= c2; i++) {
            last_valid = dp[0];
            dp[0] = 0;
            for (int j = 1; j <= c1; j++) {
                int temp = dp[j];
                dp[j] = dp[j - 1] + (s[j - 1] == t[i - 1] ? last_valid : 0);
                last_valid = temp;
            }
        }
        return dp[c1];
    }
};
// @lc code=end
