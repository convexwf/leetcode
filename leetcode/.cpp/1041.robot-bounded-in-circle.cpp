/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
 */

// @lc code=start
// 1. 模拟
// 2023-10-23 submission
// 117/117 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.5 MB, less than 28.55% of cpp online submissions.
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int d = 0;
        for (char c : instructions) {
            if (c == 'G') {
                if (d == 0) {
                    y++;
                }
                else if (d == 1) {
                    x++;
                }
                else if (d == 2) {
                    y--;
                }
                else {
                    x--;
                }
            }
            else if (c == 'L') {
                d = (d + 3) % 4;
            }
            else {
                d = (d + 1) % 4;
            }
        }
        return x == 0 && y == 0 || d != 0;
    }
};
// @lc code=end
