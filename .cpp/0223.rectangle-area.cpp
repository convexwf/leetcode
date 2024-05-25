/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
// 1. 计算交叉部分
// 2022-08-26 submission
// 3080/3080 cases passed
// Runtime: 8 ms, faster than 74.09% of cpp online submissions.
// Memory Usage: 5.8 MB, less than 77.72% of cpp online submissions.
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        int width = min(ax2, bx2) - max(ax1, bx1);
        int height = min(ay2, by2) - max(ay1, by1);
        int overlap = max(width, 0) * max(height, 0);
        return area1 + area2 - overlap;
    }
};
// @lc code=end
