/*
 * @lc app=leetcode id=991 lang=cpp
 *
 * [991] Broken Calculator
 */

// @lc code=start
// 1. 递归
// 2023-11-10 submission
// 84/84 cases passed
// Runtime: 2 ms, faster than 52.84% of cpp online submissions.
// Memory Usage: 6.2 MB, less than 64.69% of cpp online submissions.
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (startValue >= target) {
            return startValue - target;
        }
        if (target % 2 == 0) {
            return 1 + brokenCalc(startValue, target / 2);
        }
        return 1 + brokenCalc(startValue, target + 1);
    }
};
// @lc code=end
