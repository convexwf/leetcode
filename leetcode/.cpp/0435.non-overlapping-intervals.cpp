/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
// 1. 排序+贪心算法
// 2023-02-02 submission
// 58/58 cases passed
// Runtime: 437 ms, faster than 90.59% of cpp online submissions.
// Memory Usage: 89.9 MB, less than 50.93% of cpp online submissions.
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0, n = intervals.size(), last = 0;
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < intervals[last][1]) {
                ++res;
                if (intervals[i][1] < intervals[last][1]) {
                    last = i;
                }
            }
            else {
                last = i;
            }
        }
        return res;
    }
};
// @lc code=end
