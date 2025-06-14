/*
 * @lc app=leetcode id=964 lang=cpp
 *
 * [964] Least Operators to Express Number
 */

// @lc code=start
// 1. 分类讨论
// 2025-06-08 submission
// 162/162 cases passed
// Runtime: 12 ms, faster than 16.13% of cpp online submissions.
// Memory Usage: 7.8 MB, less than 85.48% of cpp online submissions.
class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        if (x == target) {
            return 0;
        }
        if (x > target) {
            return min(target * 2 - 1, (x - target) * 2);
        }
        long sum = x;
        int cnt = 0;
        while (sum < target) {
            sum *= x;
            ++cnt;
        }
        if (sum == target) {
            return cnt;
        }
        int res1 = INT_MAX, res2 = INT_MAX;
        if (sum - target < target) {
            res1 = leastOpsExpressTarget(x, sum - target) + cnt;
        }
        res2 = leastOpsExpressTarget(x, target - (sum / x)) + cnt - 1;
        return min(res1, res2) + 1;
    }
};
// @lc code=end
