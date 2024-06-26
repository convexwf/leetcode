/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
// 1. 动态规划
// 2023-01-14 submission
// 19/19 cases passed
// Runtime: 3 ms, faster than 42.82% of cpp online submissions.
// Memory Usage: 6.2 MB, less than 14.21% of cpp online submissions.
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
// @lc code=end

// @lc code=start
// 2. 数学方法
// 2023-01-14 submission
// 19/19 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 94.91% of cpp online submissions.
class Solution {
public:
    int numTrees(int n) {
        long res = 1;
        for (int i = n + 1; i <= 2 * n; ++i) {
            res = res * i / (i - n);
        }
        return res / (n + 1);
    }
};
// @lc code=end
