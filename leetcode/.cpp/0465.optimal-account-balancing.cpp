/*
 * @lc app=leetcode id=465 lang=cpp
 *
 * [465] Optimal Account Balancing
 */

// @lc code=start
// 1. 子集枚举+位操作+动态规划
class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
        for (const vector<int>& t : transactions) {
            balance[t[0]] -= t[2];
            balance[t[1]] += t[2];
        }
        vector<int> candidates;
        for (const auto& [_, b] : balance) {
            if (b != 0) {
                candidates.push_back(b);
            }
        }

        int n = candidates.size();
        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;
        for (int s = 1; s < (1 << n); ++s) {
            for (int submask = s; submask != 0; submask = (submask - 1) & submask) {
                subset_sum = 0;
                for (int i = 0; i < n; ++i) {
                    if (submask & (1 << i)) {
                        subset_sum += candidates[i];
                    }
                }
                if (subset_sum == 0) {
                    dp[s] = min(dp[s], dp[s ^ submask] + 1);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
// @lc code=end
