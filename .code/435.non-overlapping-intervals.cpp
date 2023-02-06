/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 *
 * https://leetcode.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (50.10%)
 * Likes:    5453
 * Dislikes: 152
 * Total Accepted:    339.3K
 * Total Submissions: 677.3K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
 *
 * Given an array of intervals intervals where intervals[i] = [starti, endi],
 * return the minimum number of intervals you need to remove to make the rest
 * of the intervals non-overlapping.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of the intervals are
 * non-overlapping.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of the intervals
 * non-overlapping.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: intervals = [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're
 * already non-overlapping.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * -5 * 10^4 <= starti < endi <= 5 * 10^4
 * 
 * 
 */

// @lc code=start
// 2023-02-02 submission
// 58/58 cases passed
// Runtime: 437 ms, faster than 90.59% of C++ online submissions.
// Memory Usage: 89.9 MB, less than 50.93% of C++ online submissions.
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0, n = intervals.size(), last = 0;
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < intervals[last][1]) {
                ++res;
                if (intervals[i][1] < intervals[last][1]) last = i;
            } else {
                last = i;
            }
        }
        return res;
    }
};
// @lc code=end