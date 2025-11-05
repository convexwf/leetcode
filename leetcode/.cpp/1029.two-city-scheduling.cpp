/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */

// @lc code=start
// 1. 贪心算法
// 2023-07-19 submission
// 50/50 cases passed
// Runtime: 4 ms, faster than 84.53% of cpp online submissions.
// Memory Usage: 7.8 MB, less than 64.75% of cpp online submissions.
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int totalCost = 0;
        for (int i = 0; i < n; ++i) {
            totalCost += costs[i][0];
        }
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = costs[i][1] - costs[i][0];
        }
        sort(diff.begin(), diff.end());
        for (int i = 0; i < n / 2; ++i) {
            totalCost += diff[i];
        }
        return totalCost;
    }
};
// @lc code=end
