/*
 * @lc app=leetcode id=469 lang=cpp
 *
 * [469] Convex Polygon
 */

// @lc code=start
// 1. 数学方法
class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        long pre = 0;
        for (int i = 0; i < n; ++i) {
            long x1 = points[(i + 1) % n][0] - points[i][0];
            long y1 = points[(i + 1) % n][1] - points[i][1];
            long x2 = points[(i + 2) % n][0] - points[i][0];
            long y2 = points[(i + 2) % n][1] - points[i][1];
            long cur = x1 * y2 - x2 * y1;
            if (cur) {
                if (cur * pre < 0) {
                    return false;
                }
                pre = cur;
            }
        }
        return true;
    }
};
// @lc code=end
