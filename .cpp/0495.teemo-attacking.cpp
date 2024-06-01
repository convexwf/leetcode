/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

// @lc code=start
// 1. 一次遍历
// 2022-08-26 submission
// 40/40 cases passed
// Runtime: 46 ms, faster than 88.73% of cpp online submissions.
// Memory Usage: 26 MB, less than 10.09% of cpp online submissions.
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        for (int i = 1; i < timeSeries.size(); ++i) {
            res += min(duration, timeSeries[i] - timeSeries[i - 1]);
        }
        return res + duration;
    }
};
// @lc code=end
