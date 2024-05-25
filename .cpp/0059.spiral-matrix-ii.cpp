/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
// 1. 模拟
// 2022-07-20 submission
// 20/20 cases passed
// Runtime: 6 ms, faster than 12.04% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 18.41% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res(n, vector<int>(n, 0));
        int di = 0, x = 0, y = -1;
        for (int i = 1; i <= n * n; i++) {
            if (0 > x + direction[di][0] || x + direction[di][0] >= n || 0 > y + direction[di][1] ||
                y + direction[di][1] >= n || res[x + direction[di][0]][y + direction[di][1]] != 0) {
                di = (di + 1) % 4;
            }
            x += direction[di][0];
            y += direction[di][1];
            res[x][y] = i;
        }
        return res;
    }
};
// @lc code=end
