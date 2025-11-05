/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
// 1. 排序
// 2024-06-17 submission
// 170/170 cases passed
// Runtime: 27 ms, faster than 33.03% of cpp online submissions.
// Memory Usage: 22.6 MB, less than 89.21% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.empty()) return result;
        // 对二维向量调用sort()函数，二维向量就会按第一列元素排序
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
// @lc code=end
