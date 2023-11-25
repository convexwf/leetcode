/*
 * @lc app=leetcode id=1037 lang=cpp
 *
 * [1037] Valid Boomerang
 */

// @lc code=start
// 1. 数学方法
// 2023-11-23 submission
// 206/206 cases passed
// Runtime: 5 ms, faster than 30.24% of cpp online submissions.
// Memory Usage: 10.9 MB, less than 11.71% of cpp online submissions.
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        return (points[1][1] - points[0][1]) * (points[2][0] - points[1][0]) !=
               (points[2][1] - points[1][1]) * (points[1][0] - points[0][0]);
    }
};
// @lc code=end
