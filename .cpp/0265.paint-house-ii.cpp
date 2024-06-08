/*
 * @lc app=leetcode id=265 lang=cpp
 *
 * [265] Paint House II
 */

// @lc code=start
// 1. 动态规划
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        vector<vector<int>> dp = costs;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                dp[i][j] = costs[i][j] + minCost(dp[i - 1], j);
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }

    int minCost(const vector<int>& dp, int j) {
        int min_cost = INT_MAX;
        for (int i = 0; i < dp.size(); ++i) {
            if (i != j) {
                min_cost = min(min_cost, dp[i]);
            }
        }
        return min_cost;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划-空间优化
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        if (n == 0 || k == 0) return 0;
        int min1 = 0, min2 = 0, idx1 = -1;
        for (int i = 0; i < n; ++i) {
            int m1 = INT_MAX, m2 = INT_MAX, id1 = -1;
            for (int j = 0; j < k; ++j) {
                int cost = costs[i][j] + (j == idx1 ? min2 : min1);
                if (cost < m1) {
                    m2 = m1;
                    m1 = cost;
                    id1 = j;
                }
                else if (cost < m2) {
                    m2 = cost;
                }
            }
            min1 = m1;
            min2 = m2;
            idx1 = id1;
        }
        return min1;
    }
};
// @lc code=end
