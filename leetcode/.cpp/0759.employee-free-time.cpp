/*
 * @lc app=leetcode id=759 lang=cpp
 *
 * [759] Employee Free Time
 */

// @lc code=start
// 1. 排序
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        vector<Interval> all;
        for (auto &s : schedule) {
            all.insert(all.end(), s.begin(), s.end());
        }
        sort(all.begin(), all.end(), [](Interval &a, Interval &b) { return a.start < b.start; });
        int end = all[0].end;
        for (int i = 1; i < all.size(); ++i) {
            if (all[i].start > end) {
                res.push_back(Interval(end, all[i].start));
            }
            end = max(end, all[i].end);
        }
        return res;
    }
};
// @lc code=end
