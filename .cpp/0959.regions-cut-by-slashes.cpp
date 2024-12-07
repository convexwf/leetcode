/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 */

// @lc code=start
// 1. dfs
// 2023-09-12 submission
// 137/137 cases passed
// Runtime: 18 ms, faster than 34.46% of cpp online submissions.
// Memory Usage: 11.5 MB, less than 33.33% of cpp online submissions.
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> g(3 * n, vector<int>(3 * n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    g[i * 3][j * 3 + 2] = 1;
                    g[i * 3 + 1][j * 3 + 1] = 1;
                    g[i * 3 + 2][j * 3] = 1;
                }
                else if (grid[i][j] == '\\') {
                    g[i * 3][j * 3] = 1;
                    g[i * 3 + 1][j * 3 + 1] = 1;
                    g[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 3 * n; ++i) {
            for (int j = 0; j < 3 * n; ++j) {
                if (g[i][j] == 0) {
                    dfs(g, i, j);
                    ++res;
                }
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<int>>& g, int i, int j) {
        if (i < 0 || i >= g.size() || j < 0 || j >= g.size() || g[i][j] == 1) return;
        g[i][j] = 1;
        dfs(g, i - 1, j);
        dfs(g, i + 1, j);
        dfs(g, i, j - 1);
        dfs(g, i, j + 1);
    }
};
// @lc code=end
