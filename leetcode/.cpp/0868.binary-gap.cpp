/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 */

// @lc code=start
// 1. 位运算
// 2023-07-04 submission
// 261/261 cases passed
// Runtime: 4 ms, faster than 36.73% of cpp online submissions.
// Memory Usage:  MB, less than 22.27% of cpp online submissions.
class Solution {
public:
    int binaryGap(int n) {
        int res = 0, pre = -1;
        while (n > 0) {
            int t = (int)log2(n & -n);
            if (pre != -1) res = max(res, t - pre);
            n &= n - 1;
            pre = t;
        }
        return res;
    }
};
// @lc code=end
