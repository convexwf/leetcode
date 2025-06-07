/*
 * @lc app=leetcode id=757 lang=cpp
 *
 * [757] Set Intersection Size At Least Two
 */

// @lc code=start
// 1. 排序+贪心算法
// 2025-06-04 submission
// 117/117 cases passed
// Runtime: 4 ms, faster than 57.71% of cpp online submissions.
// Memory Usage: 21.6 MB, less than 90.31% of cpp online submissions.
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });
        int ans = 0;
        int s = -1, e = -1;
        for (const vector<int>& interval : intervals) {
            int a = interval[0], b = interval[1];
            if (a <= s) continue;
            if (a > e) {
                ans += 2;
                s = b - 1;
                e = b;
            }
            else {
                ans += 1;
                s = e;
                e = b;
            }
        }
        return ans;
    }
};
// @lc code=end
