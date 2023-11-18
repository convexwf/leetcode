/*
 * @lc app=leetcode id=517 lang=cpp
 *
 * [517] Super Washing Machines
 */

// @lc code=start
// 1. 贪心算法
// 2023-11-15 submission
// 120/120 cases passed
// Runtime: 7 ms, faster than 100% of cpp online submissions.
// Memory Usage: 13.4 MB, less than 40.57% of cpp online submissions.
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % n != 0) return -1;
        int k = sum / n;
        int res = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            s += machines[i] - k;
            res = max(res, max(abs(s), machines[i] - k));
        }
        return res;
    }
};
// @lc code=end
