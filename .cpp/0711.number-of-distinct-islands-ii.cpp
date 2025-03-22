/*
 * @lc app=leetcode id=711 lang=cpp
 *
 * [711] Number of Distinct Islands II
 */

// @lc code=start
// 1. 排序+哈希表+dfs
class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<vector<vector<int>>> islands;
        vector<vector<int>> shapes;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    shape.clear();
                    dfs(grid, i, j, shapes);
                    islands.insert(normalize(shapes));
                }
            }
        }
        return islands.size();
    }

    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& shapes) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return;
        }
        grid[x][y] = 0;
        shapes.push_back({x, y});
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (const vector<int>& dir : dirs) {
            dfs(grid, x + dir[0], y + dir[1], shapes);
        }
    }

    vector<vector<int>> normalize(vector<vector<int>>& shapes) {
        vector<vector<vector<int>>> ans(8);
        for (const vector<int>& p : shapes) {
            int x = p[0], y = p[1];
            ans[0].push_back({x, y});
            ans[1].push_back({x, -y});
            ans[2].push_back({-x, y});
            ans[3].push_back({-x, -y});
            ans[4].push_back({y, x});
            ans[5].push_back({y, -x});
            ans[6].push_back({-y, x});
            ans[7].push_back({-y, -x});
        }
        for (vector<vector<int>>& a : ans) {
            sort(a.begin(), a.end());
            for (int i = 1; i < a.size(); i++) {
                a[i][0] -= a[0][0];
                a[i][1] -= a[0][1];
            }
            a[0] = {0, 0};
        }
        sort(ans.begin(), ans.end());
        return ans[0];
    }
};
// @lc code=end
