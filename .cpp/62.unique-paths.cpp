/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
// 1. 动态规划
// 2022-07-20 submission
// 63/63 cases passed
// Runtime: 4 ms, faster than 28.4% of C++ online submissions.
// Memory Usage: 6.1 MB, less than 57.4% of C++ online submissions.
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end

// @lc code=start
// 2. 组合数学
// 2022-07-20 submission
// 63/63 cases passed
// Runtime: 3 ms, faster than 44.06% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 90.25% of C++ online submissions.
class Solution {
public:
    int uniquePaths(int m, int n) {
        double num = 1, denom = 1;
        int small = m > n ? n : m;
        for (int i = 1; i <= small - 1; ++i) {
            num *= (m + n - 1 - i);
            denom *= i;
        }
        return (int)(num / denom);
    }
};
// @lc code=end
