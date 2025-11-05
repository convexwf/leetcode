/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
// 1. 贪心算法
// 2023-11-20 submission
// 50/50 cases passed
// Runtime: 325 ms, faster than 95.09% of cpp online submissions.
// Memory Usage: 90.2 MB, less than 42.6% of cpp online submissions.
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int right = points[0][1];
        int res = 1;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= right) {
                right = min(right, points[i][1]);
            }
            else {
                ++res;
                right = points[i][1];
            }
        }
        return res;
    }
};
// @lc code=end
