/*
 * @lc app=leetcode id=803 lang=cpp
 *
 * [803] Bricks Falling When Hit
 */

// @lc code=start
// 1. dfs
// 2025-06-09 submission
// 40/40 cases passed
// Runtime: 42 ms, faster than 46.52% of cpp online submissions.
// Memory Usage: 119.5 MB, less than 38.16% of cpp online submissions.
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size(), k = hits.size();
        vector<int> res(k);
        unordered_set<int> noDrop;
        for (int i = 0; i < k; ++i) {
            grid[hits[i][0]][hits[i][1]] -= 1;
        }
        for (int i = 0; i < n; ++i) {
            if (grid[0][i] == 1) {
                check(grid, 0, i, noDrop);
            }
        }
        for (int i = k - 1; i >= 0; --i) {
            int oldSize = noDrop.size(), x = hits[i][0], y = hits[i][1];
            if (++grid[x][y] != 1) continue;
            if ((x - 1 >= 0 && noDrop.count((x - 1) * n + y)) ||
                (x + 1 < m && noDrop.count((x + 1) * n + y)) ||
                (y - 1 >= 0 && noDrop.count(x * n + y - 1)) ||
                (y + 1 < n && noDrop.count(x * n + y + 1)) || x == 0) {
                check(grid, x, y, noDrop);
                res[i] = noDrop.size() - oldSize - 1;
            }
        }
        return res;
    }

    void check(vector<vector<int>>& grid, int i, int j, unordered_set<int>& noDrop) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1 || noDrop.count(i * n + j)) {
            return;
        }
        noDrop.insert(i * n + j);
        check(grid, i - 1, j, noDrop);
        check(grid, i + 1, j, noDrop);
        check(grid, i, j - 1, noDrop);
        check(grid, i, j + 1, noDrop);
    }
};
// @lc code=end

// @lc code=start
// 2. 并查集
// 2025-06-09 submission
// 40/40 cases passed
// Runtime: 43 ms, faster than 46.24% of cpp online submissions.
// Memory Usage: 114.2 MB, less than 60.45% of cpp online submissions.
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        vector<int> parent(m * n + 1);
        vector<int> size(m * n + 1, 1);

        for (int i = 0; i < m * n + 1; ++i) {
            parent[i] = i;
        }

        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = grid[i][j];
            }
        }
        for (const vector<int>& h : hits) {
            matrix[h[0]][h[1]] = 0; // 打掉砖块
        }
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 1) {
                merge(parent, size, j, m * n); // 将第一行的砖块与虚拟节点合并
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) continue;
                if (matrix[i - 1][j] == 1) {
                    merge(parent, size, i * n + j, (i - 1) * n + j); // 上方砖块
                }
                if (j > 0 && matrix[i][j - 1] == 1) {
                    merge(parent, size, i * n + j, i * n + (j - 1)); // 左侧砖块
                }
            }
        }

        vector<int> result(hits.size());
        vector<int> directions = {0, -1, 0, 1, 0};
        for (int k = hits.size() - 1; k >= 0; --k) {
            int i = hits[k][0], j = hits[k][1];
            if (grid[i][j] == 0) continue;            // 如果没有砖块，跳过
            matrix[i][j] = 1;                         // 恢复砖块
            int prevSize = size[find(parent, m * n)]; // 恢复前的大小
            if (i == 0) {
                merge(parent, size, j, m * n); // 如果在第一行，直接与虚拟节点合并
            }
            for (int l = 0; l < 4; ++l) {
                int x = i + directions[l], y = j + directions[l + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] == 1) {
                    merge(parent, size, i * n + j, x * n + y); // 合并四个方向的砖块
                }
            }
            int currSize = size[find(parent, m * n)];    // 恢复后的大小
            result[k] = max(0, currSize - prevSize - 1); // 减去恢复前的大小和当前砖块
        }
        return result;
    }

private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    void merge(vector<int>& parent, vector<int>& size, int a, int b) {
        int pa = find(parent, a);
        int pb = find(parent, b);
        if (pa != pb) {
            parent[pa] = pb;
            size[pb] += size[pa];
        }
    }
};
// @lc code=end
