/*
 * @lc app=leetcode id=624 lang=cpp
 *
 * [624] Maximum Distance in Arrays
 */

// @lc code=start
// 1. 贪心算法
// 2024-08-28 submission
// 136/136 cases passed
// Runtime: 234 ms, faster than 39.18% of cpp online submissions.
// Memory Usage: 107.9 MB, less than 72.36% of cpp online submissions.
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int min_val = arrays[0].front(), max_val = arrays[0].back();
        for (int i = 1; i < arrays.size(); i++) {
            res = max(res, max(abs(arrays[i].front() - max_val), abs(arrays[i].back() - min_val)));
            min_val = min(min_val, arrays[i].front());
            max_val = max(max_val, arrays[i].back());
        }
        return res;
    }
};
// @lc code=end
