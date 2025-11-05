/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */

// @lc code=start
// 1. 模拟
// 2024-11-08 submission
// 73/73 cases passed
// Runtime: 7 ms, faster than 45.76% of cpp online submissions.
// Memory Usage:  MB, less than 20.33% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int step = 1, cnt = 0, dir = 0;
        res.push_back({rStart, cStart});
        cnt++;
        while (cnt < rows * cols) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < step; j++) {
                    rStart += dirs[dir][0];
                    cStart += dirs[dir][1];
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        res.push_back({rStart, cStart});
                        cnt++;
                    }
                }
                dir = (dir + 1) % 4;
                if (dir % 2 == 0) {
                    step++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
