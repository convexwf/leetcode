/*
 * @lc app=leetcode id=276 lang=cpp
 *
 * [276] Paint Fence
 */

// @lc code=start
// 1. 动态规划
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = k;
        dp[0][1] = 0;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) * (k - 1);
            dp[i][1] = dp[i - 1][0];
        }
        return dp[n - 1][0] + dp[n - 1][1];
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划-空间优化
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        int same = 0, diff = k;
        for (int i = 1; i < n; ++i) {
            int tmp = diff;
            diff = (same + diff) * (k - 1);
            same = tmp;
        }
        return same + diff;
    }
};
// @lc code=end
