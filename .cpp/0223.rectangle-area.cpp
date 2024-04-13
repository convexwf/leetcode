/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
// 2022-08-26 submission
// 3080/3080 cases passed
// Runtime: 8 ms, faster than 74.09% of cpp online submissions.
// Memory Usage: 5.8 MB, less than 77.72% of cpp online submissions.
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum1 = (C - A) * (D - B), sum2 = (H - F) * (G - E);
        if (E >= C || F >= D || B >= H || A >= G) {
            return sum1 + sum2;
        }
        return sum1 - ((min(G, C) - max(A, E)) * (min(D, H) - max(B, F))) + sum2;
    }
};
// @lc code=end
