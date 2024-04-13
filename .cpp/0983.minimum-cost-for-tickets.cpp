/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
// 1. 动态规划
// 2023-10-16 submission
// 70/70 cases passed
// Runtime: 3 ms, faster than 61.57% of cpp online submissions.
// Memory Usage: 9.7 MB, less than 59.47% of cpp online submissions.
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        unordered_set<int> travel(days.begin(), days.end());
        vector<int> dp(days[n - 1] + 1, 0);
        for (int i = 1; i <= days[n - 1]; ++i) {
            if (!travel.count(i)) {
                dp[i] = dp[i - 1];
            }
            else {
                dp[i] = min(dp[i - 1] + costs[0],
                            min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]));
            }
        }
        return dp[days[n - 1]];
    }
};
// @lc code=end
