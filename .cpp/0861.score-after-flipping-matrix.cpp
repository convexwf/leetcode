/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 */

// @lc code=start
// 1. 贪婪算法
// 2023-09-27 submission
// 80/80 cases passed
// Runtime: 5 ms, faster than 34.11% of cpp online submissions.
// Memory Usage: 8.5 MB, less than 11.37% of cpp online submissions.
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = m * (1 << (n - 1));
        for (int j = 1; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][0] == 1) {
                    cnt += grid[i][j];
                }
                else {
                    cnt += (1 - grid[i][j]);
                }
            }
            cnt = max(cnt, m - cnt);
            ans += cnt * (1 << (n - j - 1));
        }
        return ans;
    }
};
// @lc code=end
