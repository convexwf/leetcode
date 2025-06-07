/*
 * @lc app=leetcode id=471 lang=cpp
 *
 * [471] Encode String with Shortest Length
 */

// @lc code=start
// 1. 动态规划
class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n));

        auto check = [&](int i, int j) {
            string t = s.substr(i, j - i + 1);
            if (t.size() < 5) {
                return t;
            }
            int k = (t + t).find(t, 1);
            if (k < t.size()) {
                int cnt = t.size() / k;
                return to_string(cnt) + "[" + f[i][i + k - 1] + "]";
            }
            return t;
        };

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = check(i, j);
                if (j - i + 1 >= 5) {
                    for (int k = i; k < j; ++k) {
                        string t = dp[i][k] + dp[k + 1][j];
                        if (t.size() < dp[i][j].size()) {
                            dp[i][j] = t;
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end
