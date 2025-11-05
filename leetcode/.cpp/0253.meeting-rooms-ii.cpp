/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 */

// @lc code=start
// 1. 差分数组
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        int m = 0;
        for (int i = 0; i < n; ++i) {
            m = max(m, intervals[i][1]);
        }
        vector<int> diff(m + 1, 0);
        for (int i = 0; i < n; ++i) {
            diff[intervals[i][0]] += 1;
            if (intervals[i][1] + 1 <= m) {
                diff[intervals[i][1] + 1] -= 1;
            }
        }
        int res = 0, sum = 0;
        for (int i = 0; i <= m; ++i) {
            sum += diff[i];
            res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end
