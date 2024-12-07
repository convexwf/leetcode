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
