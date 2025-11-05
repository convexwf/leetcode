/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
// 1. 枚举+双指针
// 2023-08-02 submission
// 127/127 cases passed
// Runtime: 3 ms, faster than 65.98% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 75.19% of cpp online submissions.
class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0, b = sqrt(c);
        while (a <= b) {
            int diff = c - b * b;
            if (diff == a * a) {
                return true;
            }
            else if (diff > a * a) {
                ++a;
            }
            else {
                --b;
            }
        }
        return false;
    }
};
// @lc code=end
