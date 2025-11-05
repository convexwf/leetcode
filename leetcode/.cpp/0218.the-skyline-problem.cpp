/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
// 1. 排序+多重有序集合
// 2025-02-19 submission
// 44/44 cases passed
// Runtime: 11 ms, faster than 86.85% of cpp online submissions.
// Memory Usage: 27.7 MB, less than 76.03% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        if (buildings.empty()) {
            return res;
        }
        vector<pair<int, int>> points;
        for (const vector<int>& building : buildings) {
            points.push_back({building[0], -building[2]});
            points.push_back({building[1], building[2]});
        }
        sort(points.begin(), points.end());
        multiset<int> heights = {0};
        int pre = 0;
        for (const pair<int>& point : points) {
            if (point.second < 0) {
                heights.insert(-point.second);
            }
            else {
                heights.erase(heights.find(point.second));
            }
            int cur = *heights.rbegin();
            if (cur != pre) {
                res.push_back({point.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};
// @lc code=end
