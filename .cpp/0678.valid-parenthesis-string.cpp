/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
// 1. 动态规划
// 2023-11-21 submission
// 83/83 cases passed
// Runtime: 112 ms, faster than 5.03% of cpp online submissions.
// Memory Usage:  MB, less than 12.97% of cpp online submissions.
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') dp[i][i] = true;
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if ((s[i] == '(' || s[i] == '*') && (s[j] == ')' || s[j] == '*')) {
                    if (j - i == 1)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                // 剪枝：如果dp[i][j]已经为true，就不需要再计算了
                for (int k = i; k < j && !dp[i][j]; ++k) {
                    dp[i][j] = dp[i][k] && dp[k + 1][j];
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

// @lc code=start
// 2. 贪心算法+两次扫描
// 2023-11-21 submission
// 83/83 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.4 MB, less than 97.26% of cpp online submissions.
class Solution {
public:
    bool checkValidString(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(' || c == '*') {
                count++;
            }
            else {
                count--;
            }
            if (count < 0) {
                return false;
            }
        }
        count = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (c == ')' || c == '*') {
                count++;
            }
            else {
                count--;
            }
            if (count < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
