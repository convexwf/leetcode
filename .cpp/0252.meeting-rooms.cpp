/*
 * @lc app=leetcode id=252 lang=cpp
 *
 * [252] Meeting Rooms
 */

// @lc code=start
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
