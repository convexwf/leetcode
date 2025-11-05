/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

// @lc code=start
// 1. 动态规划
// 2023-12-29 submission
// 198/198 cases passed
// Runtime: 134 ms, faster than 6.81% of cpp online submissions.
// Memory Usage: 16.6 MB, less than 55.84% of cpp online submissions.
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = startFuel;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (dp[j] >= stations[i][0]) {
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }
            }
        }
        for (int i = 0; i <= n; ++i) {
            if (dp[i] >= target) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

// @lc code=start
// 2. 最大堆+贪心算法
// 2023-12-29 submission
// 198/198 cases passed
// Runtime: 22 ms, faster than 64.2% of cpp online submissions.
// Memory Usage: 16.4 MB, less than 84.05% of cpp online submissions.
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int cur = startFuel, res = 0, i = 0;
        while (cur < target) {
            while (i < stations.size() && stations[i][0] <= cur) {
                pq.push(stations[i++][1]);
            }
            if (pq.empty()) return -1;
            cur += pq.top();
            pq.pop();
            ++res;
        }
        return res;
    }
};
// @lc code=end
