/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start
// 2025-02-08 submission
// 90/90 cases passed
// Runtime: 5 ms, faster than 27.02% of cpp online submissions.
// Memory Usage:  MB, less than 72.98% of cpp online submissions.
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= stones[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - stones[i - 1]];
                }
            }
        }
        for (int j = target; j >= 0; --j) {
            if (dp[n][j]) {
                return sum - 2 * j;
            }
        }
        return 0;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划-空间优化
// 2025-02-08 submission
// 90/90 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 10.4 MB, less than 91.84% of cpp online submissions.
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = target; j >= stones[i - 1]; --j) {
                dp[j] = dp[j] || dp[j - stones[i - 1]];
            }
        }
        for (int j = target; j >= 0; --j) {
            if (dp[j]) {
                return sum - 2 * j;
            }
        }
        return 0;
    }
};
// @lc code=end
