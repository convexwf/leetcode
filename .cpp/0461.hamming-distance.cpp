/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
// 1. 位操作
// 2022-08-26 submission
// 149/149 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 26.57% of cpp online submissions.
class Solution {
public:
    int hammingDistance(int x, int y) {
        int merge = x ^ y;
        int res = 0;
        while (merge > 0) {
            ++res;
            merge = merge & (merge - 1);
        }
        return res;
    }
};
// @lc code=end
