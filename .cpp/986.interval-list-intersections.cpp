/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

// @lc code=start
// 1. 双指针
// 2023-08-08 submission
// 85/85 cases passed
// Runtime: 25 ms, faster than 94.04% of cpp online submissions.
// Memory Usage: 18.5 MB, less than 85.94% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size()) {
            int a = max(firstList[i][0], secondList[j][0]);
            int b = min(firstList[i][1], secondList[j][1]);
            if (a <= b) {
                res.push_back({a, b});
            }
            if (firstList[i][1] < secondList[j][1]) {
                ++i;
            }
            else {
                ++j;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 扫描线算法
// Testcase
// [[0,2],[5,10],[13,23],[24,25]]
// [[1,5],[8,12],[15,24],[25,26]]
// Answer
// [[1,2],[8,10],[15,23]]
// Expected Answer
// [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        vector<pair<int, int>> points;
        for (auto& interval : firstList) {
            points.push_back({interval[0], 1});
            points.push_back({interval[1], -1});
        }
        for (auto& interval : secondList) {
            points.push_back({interval[0], 1});
            points.push_back({interval[1], -1});
        }
        sort(points.begin(), points.end());
        int cnt = 0;
        int start = 0;
        for (auto& point : points) {
            if (point.second == 1) {
                cnt++;
                if (cnt == 2) {
                    start = point.first;
                }
            }
            else {
                cnt--;
                if (cnt == 1) {
                    if (point.first == start) {
                        res.push_back({start, start});
                    }
                    else {
                        res.push_back({start, point.first});
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
