/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
// 1. dfs
// 2023-05-25 submission
// 113/113 cases passed
// Runtime: 47 ms, faster than 60.09% of cpp online submissions.
// Memory Usage: 17.8 MB, less than % of cpp online submissions.
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            dfs(heights, visited, 1, INT_MIN, i, 0);
            dfs(heights, visited, 2, INT_MIN, i, n - 1);
        }
        for (int i = 0; i < n; ++i) {
            dfs(heights, visited, 1, INT_MIN, 0, i);
            dfs(heights, visited, 2, INT_MIN, m - 1, i);
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] == 3) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int mark, int pre, int i,
             int j) {
        int m = heights.size(), n = heights[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || (visited[i][j] & mark) || heights[i][j] < pre)
            return;
        visited[i][j] += mark;
        dfs(heights, visited, mark, heights[i][j], i + 1, j);
        dfs(heights, visited, mark, heights[i][j], i - 1, j);
        dfs(heights, visited, mark, heights[i][j], i, j + 1);
        dfs(heights, visited, mark, heights[i][j], i, j - 1);
    }
};
// @lc code=end

// @lc code=start
// 2. bfs
// 2023-05-25 submission
// 113/113 cases passed
// Runtime: 93 ms, faster than 17.76% of cpp online submissions.
// Memory Usage: 24.9 MB, less than 16.57% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        vector<vector<int>> res;
        int m = heights.size(), n = heights[0].size();
        queue<pair<int, int>> q1, q2;
        vector<vector<bool>> pacific(m, vector<bool>(n, false)), atlantic = pacific;
        for (int i = 0; i < m; ++i) {
            q1.push({i, 0});
            q2.push({i, n - 1});
            pacific[i][0] = true;
            atlantic[i][n - 1] = true;
        }
        for (int i = 0; i < n; ++i) {
            q1.push({0, i});
            q2.push({m - 1, i});
            pacific[0][i] = true;
            atlantic[m - 1][i] = true;
        }
        bfs(heights, pacific, q1);
        bfs(heights, atlantic, q2);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    void bfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (auto dir : dirs) {
                int x = t.first + dir[0], y = t.second + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] ||
                    matrix[x][y] < matrix[t.first][t.second])
                    continue;
                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }
};
// @lc code=end
