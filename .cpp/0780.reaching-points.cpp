/*
 * @lc app=leetcode id=780 lang=cpp
 *
 * [780] Reaching Points
 */

// @lc code=start
// 1. 逆向转换
// 2024-01-30 submission
// 196/196 cases passed
// Runtime: 3 ms, faster than 37.8% of cpp online submissions.
// Memory Usage: 7.1 MB, less than 12.6% of cpp online submissions.
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == ty) break;
            if (tx > ty) {
                if (ty > sy)
                    tx %= ty;
                else
                    return (tx - sx) % ty == 0;
            }
            else {
                if (tx > sx)
                    ty %= tx;
                else
                    return (ty - sy) % tx == 0;
            }
        }
        return (tx == sx && ty == sy);
    }
};
// @lc code=end
