/*
 * @lc app=leetcode id=1033 lang=cpp
 *
 * [1033] Moving Stones Until Consecutive
 */

// @lc code=start
// 1. 贪心算法
// 2024-01-05 submission
// 187/187 cases passed
// Runtime: 3 ms, faster than 48.6% of cpp online submissions.
// Memory Usage: 6.7 MB, less than 25.23% of cpp online submissions.
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        if (v[2] - v[0] == 2) return {0, 0};
        if (v[1] - v[0] <= 2 || v[2] - v[1] <= 2) return {1, v[2] - v[0] - 2};
        return {2, v[2] - v[0] - 2};
    }
};
// @lc code=end
