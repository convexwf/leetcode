/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
// 1. 一次遍历
// 2023-11-29 submission
// 54/54 cases passed
// Runtime: 27 ms, faster than 99.2% of cpp online submissions.
// Memory Usage: 41.1 MB, less than % of cpp online submissions.
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, mx = values[0] + 0;
        for (int j = 1; j < values.size(); ++j) {
            ans = max(ans, mx + values[j] - j);
            mx = max(mx, values[j] + j);
        }
        return ans;
    }
};
// @lc code=end
