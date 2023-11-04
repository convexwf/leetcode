/*
 * @lc app=leetcode id=467 lang=cpp
 *
 * [467] Unique Substrings in Wraparound String
 */

// @lc code=start
// 1. 动态规划
// 2023-11-01 submission
// 82/82 cases passed
// Runtime: 11 ms, faster than 43.52% of cpp online submissions.
// Memory Usage: 8.3 MB, less than 54.63% of cpp online submissions.
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26, 0);
        int n = s.size();
        int len = 1;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && (s[i] - s[i - 1] == 1 || s[i - 1] - s[i] == 25)) {
                ++len;
            }
            else {
                len = 1;
            }
            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], len);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
// @lc code=end
