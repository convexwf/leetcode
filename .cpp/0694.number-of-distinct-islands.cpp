/*
 * @lc app=leetcode id=694 lang=cpp
 *
 * [694] Number of Distinct Islands
 */

// @lc code=start
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {0, 1, 0, -1, 0};

        function<void(int, int, int, string&)> dfs = [&](int x, int y, int dir, string& path) {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
                return;
            }
            grid[x][y] = 0;
            path += to_string(dir);
            for (int i = 0; i < 4; ++i) {
                dfs(x + dirs[i], y + dirs[i + 1], i, path);
            }
            path += to_string(-dir);
        };

        unordered_set<string> islands;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    string path;
                    dfs(i, j, 0, path);
                    islands.insert(path);
                }
            }
        }
        return islands.size();
    }
};
// @lc code=end
