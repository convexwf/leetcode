/*
 * @lc app=leetcode id=849 lang=cpp
 *
 * [849] Maximize Distance to Closest Person
 */

// @lc code=start
// 1. 统计连续 0 的个数
// 2020-10-30 submission
// 81/81 cases passed
// Runtime: 8 ms, faster than 92.96% of cpp online submissions.
// Memory Usage: 16.9 MB, less than 87.58% of cpp online submissions.
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        if (seats.empty()) return 0;
        int res = 0;
        int pivot = -1;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                res = max(res, pivot < 0 ? (i - pivot - 1) : (i - pivot) / 2);
                pivot = i;
            }
        }
        res = max(res, int(seats.size()) - pivot - 1);
        return res;
    }
};
// @lc code=end
