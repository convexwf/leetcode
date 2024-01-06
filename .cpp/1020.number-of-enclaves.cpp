/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
// 1. DFS
// 2024-01-05 submission
// 58/58 cases passed
// Runtime: 44 ms, faster than 98.13% of cpp online submissions.
// Memory Usage: 30.5 MB, less than 53.18% of cpp online submissions.
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += grid[i][j];
            }
        }
        return ans;
    }

private:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) return;
        grid[i][j] = 0;
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};
// @lc code=end

// @lc code=start
// 2. BFS
// 2024-01-05 submission
// 58/58 cases passed
// Runtime: 63 ms, faster than 40.13% of cpp online submissions.
// Memory Usage: 26.3 MB, less than 92.82% of cpp online submissions.
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<int> q;
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1) q.push(i * n);
            if (grid[i][n - 1] == 1) q.push(i * n + n - 1);
        }
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 1) q.push(j);
            if (grid[m - 1][j] == 1) q.push((m - 1) * n + j);
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            int i = t / n, j = t % n;
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) continue;
            grid[i][j] = 0;
            q.push(t - n);
            q.push(t + n);
            q.push(t - 1);
            q.push(t + 1);
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += grid[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 3. 并查集
// 2024-01-05 submission
// 58/58 cases passed
// Runtime: 108 ms, faster than 14.07% of cpp online submissions.
// Memory Usage: 26.3 MB, less than 92.82% of cpp online submissions.
class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    void merge(vector<int>& parent, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> parent(m * n + 1);
        for (int i = 0; i < m * n + 1; ++i) {
            parent[i] = i;
        }
        int dummy = m * n;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    merge(parent, i * n + j, dummy);
                    continue;
                }
                for (auto& d : directions) {
                    int x = i + d[0];
                    int y = j + d[1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        merge(parent, i * n + j, x * n + y);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && find(parent, i * n + j) != find(parent, dummy)) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
