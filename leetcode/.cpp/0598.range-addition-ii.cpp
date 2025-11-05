/*
 * @lc app=leetcode id=598 lang=cpp
 *
 * [598] Range Addition II
 */

// @lc code=start
// 1. 模拟
// 2024-12-10 submission
// 69/69 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 15.2 MB, less than 20.14% of cpp online submissions.
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a = m, b = n;
        for (auto& op : ops) {
            a = min(a, op[0]);
            b = min(b, op[1]);
        }
        return a * b;
    }
};
// @lc code=end
