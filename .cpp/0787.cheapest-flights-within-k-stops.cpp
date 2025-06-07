/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
// 1. Bellman-Ford 算法
// 2025-06-03 submission
// 56/56 cases passed
// Runtime: 4 ms, faster than 47.72% of cpp online submissions.
// Memory Usage: 17.1 MB, less than 94.16% of cpp online submissions.
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; ++i) {
            vector<int> temp(dist);
            for (const vector<int>& flight : flights) {
                int u = flight[0], v = flight[1], price = flight[2];
                if (dist[u] != INT_MAX) {
                    temp[v] = min(temp[v], dist[u] + price);
                }
            }
            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
// @lc code=end

// @lc code=start
// 2. 记忆化搜索
// 2025-06-03 submission
// 56/56 cases passed
// Runtime: 115 ms, faster than 5.68% of cpp online submissions.
// Memory Usage: 17.3 MB, less than 93.62% of cpp online submissions.
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> memo(n, vector<int>(k + 2, -1));
        int ans = dfs(src, dst, k + 1, flights, memo);
        return ans == INT_MAX ? -1 : ans;
    }

    int dfs(int src, int dst, int k, vector<vector<int>>& flights, vector<vector<int>>& memo) {
        if (src == dst) {
            return 0;
        }
        if (k == 0) {
            return INT_MAX;
        }
        if (memo[src][k] != -1) {
            return memo[src][k];
        }

        int minCost = INT_MAX;
        for (const vector<int>& flight : flights) {
            int u = flight[0], v = flight[1], price = flight[2];
            if (u == src) {
                int cost = dfs(v, dst, k - 1, flights, memo);
                if (cost != INT_MAX) {
                    minCost = min(minCost, cost + price);
                }
            }
        }

        memo[src][k] = minCost;
        return minCost;
    }
};
// @lc code=end
