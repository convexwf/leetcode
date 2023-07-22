/*
 * @lc app=leetcode id=1030 lang=cpp
 *
 * [1030] Matrix Cells in Distance Order
 */

// @lc code=start
// 1. brute force
// 2023-07-19 submission
// 66/66 cases passed
// Runtime: 80 ms, faster than 31.06% of cpp online submissions.
// Memory Usage: 23.5 MB, less than 37.87% of cpp online submissions.
class Solution {
private:
    int manhattanDistance(int r1, int c1, int r2, int c2) {
        return abs(r1 - r2) + abs(c1 - c2);
    }

public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        std::vector<std::vector<int>> cells;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                int distance = manhattanDistance(r, c, r0, c0);
                cells.push_back({distance, r, c});
            }
        }

        std::sort(cells.begin(), cells.end());

        std::vector<std::vector<int>> result;
        for (const auto& cell : cells) {
            result.push_back({cell[1], cell[2]});
        }

        return result;
    }
};
// @lc code=end

// @lc code=start
// 2. 自定义排序
// 2023-07-19 submission
// 66/66 cases passed
// Runtime: 57 ms, faster than 61.04% of cpp online submissions.
// Memory Usage: 16.3 MB, less than 98.37% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                res.push_back({i, j});
            }
        }
        sort(res.begin(), res.end(), [&](const vector<int>& a, const vector<int>& b) {
            return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
        });
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. BFS
// 2023-07-19 submission
// 66/66 cases passed
// Runtime: 63 ms, faster than 48.77% of cpp online submissions.
// Memory Usage: 24.4 MB, less than 34.6% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> res;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<vector<int>> q;
        q.push({rCenter, cCenter});
        visited[rCenter][cCenter] = true;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            res.push_back(cur);
            for (int i = 0; i < 4; ++i) {
                int x = cur[0] + dx[i];
                int y = cur[1] + dy[i];
                if (x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y]) continue;
                q.push({x, y});
                visited[x][y] = true;
            }
        }
        return res;
    }

private:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
};
// @lc code=end
