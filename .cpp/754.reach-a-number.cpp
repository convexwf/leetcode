/*
 * @lc app=leetcode id=754 lang=cpp
 *
 * [754] Reach a Number
 */

// @lc code=start
// 1. 数学方法
// 2023-08-28 submission
// 73/73 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 14.6% of cpp online submissions.
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int res = 0, sum = 0;
        while (sum < target || (sum - target) % 2 == 1) {
            ++res;
            sum += res;
        }
        return res;
    }
};
// @lc code=end
