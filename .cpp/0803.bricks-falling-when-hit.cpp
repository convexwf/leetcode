/*
 * @lc app=leetcode id=803 lang=cpp
 *
 * [803] Bricks Falling When Hit
 */

// @lc code=start
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> uf(m * n + 1, vector<int>(m * n + 1, -1));
        vector<int> res;

        // Union-Find functions
        auto find = [&](int x) {
            if (uf[x][x] == -1) return x;
            return uf[x][x] = find(uf[x][x]);
        };

        auto unionSets = [&](int x, int y) {
            int rootX = find(x), rootY = find(y);
            if (rootX != rootY) uf[rootX][rootX] = rootY;
        };

        // Mark hits
        for (const auto& hit : hits) {
            grid[hit[0]][hit[1]] -= 1;
        }

        // Connect bricks to the roof
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] > 0) unionSets(j, m * n);
        }

        // Connect adjacent bricks
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    if (i > 0 && grid[i - 1][j] > 0) unionSets(i * n + j, (i - 1) * n + j);
                    if (j > 0 && grid[i][j - 1] > 0) unionSets(i * n + j, i * n + j - 1);
                }
            }
        }

        // Process hits in reverse order
        for (int k = hits.size() - 1; k >= 0; --k) {
            int i = hits[k][0], j = hits[k][1];
            if (grid[i][j] == -1) {
                grid[i][j] = 1;
                if (i == 0) {
                    unionSets(j, m * n);
                }
                if (i > 0 && grid[i - 1][j] > 0 && find((i - 1) * n + j) != m * n) {
                    unionSets(i * n + j, (i - 1) * n + j);
                }
                if (j > 0 && grid[i][j - 1] > 0 && find(i * n + j - 1) != m * n) {
                    unionSets(i * n + j, i * n + j - 1);
                }
                if (j < n - 1 && grid[i][j + 1] > 0 && find(i * n + j + 1) != m * n) {
                    unionSets(i * n + j, i * n + j + 1);
                }
                if (i < m - 1 && grid[i + 1][j] > 0 && find((i + 1) * n + j) != m * n) {
                    unionSets(i * n + j, (i + 1) * n + j);
                }

                // Count the number of bricks that fell
                res.push_back(find(m * n) == m * n ? 0 : grid[i][j]);
            }
            else {
                res.push_back(0);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
