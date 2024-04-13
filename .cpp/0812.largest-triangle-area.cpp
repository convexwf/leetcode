/*
 * @lc app=leetcode id=812 lang=cpp
 *
 * [812] Largest Triangle Area
 */

// @lc code=start
// 1. brute force
// 2023-06-30 submission
// 57/57 cases passed
// Runtime: 13 ms, faster than 64.78% of cpp online submissions.
// Memory Usage: 7.7 MB, less than 32.26% of cpp online submissions.
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                for (int k = j + 1; k < points.size(); ++k) {
                    res = max(res, area(points[i], points[j], points[k]));
                }
            }
        }
        return res;
    }
    double area(vector<int>& A, vector<int>& B, vector<int>& C) {
        return 0.5 * abs(A[0] * B[1] + B[0] * C[1] + C[0] * A[1] - A[0] * C[1] - B[0] * A[1] -
                         C[0] * B[1]);
    }
};
// @lc code=end
