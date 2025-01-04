/*
 * @lc app=leetcode id=960 lang=cpp
 *
 * [960] Delete Columns to Make Sorted III
 */

// @lc code=start
// 1. 动态规划
// 2024-12-30 submission
// 131/131 cases passed
// Runtime: 4 ms, faster than 55.34% of cpp online submissions.
// Memory Usage: 13.4 MB, less than 39.81% of cpp online submissions.
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<int> dp(m, 1);

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                if (check(strs, j, i)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return m - dp[m - 1];
    }

    bool check(vector<string>& strs, int j, int i) const {
        for (const string& str : strs) {
            if (str[j] > str[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
