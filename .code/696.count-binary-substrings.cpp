/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
// 2021-12-22 submission
// 91/91 cases passed
// Runtime: 30 ms, faster than 35.41% of C++ online submissions.
// Memory Usage: 14.6 MB, less than 5.79% of C++ online submissions.
class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        vector<int> dp(s.length(), 0);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i-1]) {
                dp[i] = 2;
                res += 1;
            }
            else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]!=s[i]) {
                dp[i] = dp[i-1] + 2;
                res += 1;
            }
        }
        return res;
    }
};
// @lc code=end
