/*
 * @lc app=leetcode id=505 lang=cpp
 *
 * [505] The Maze II
 */

// @lc code=start
// 1. bfs
class Solution {
public:
    // 返回值为滚动的距离
    int stop_position(vector<vector<int>>& maze, vector<int>& start, vector<int>& dir) {
        int m = maze.size(), n = maze[0].size();
        int x = start[0], y = start[1];
        int dx = dir[0], dy = dir[1];
        int distance = 0;
        while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
            x += dx;
            y += dy;
            distance++;
        }
        x -= dx;
        y -= dy;
        return distance - 1;
    }

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        unordered_set<int> visited;
        queue<vector<int>> q;
        q.push({start[0], start[1], 0});
        visited.insert(start[0] * n + start[1]);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur[0], y = cur[1], distance = cur[2];
            if (x == destination[0] && y == destination[1]) {
                return distance;
            }
            for (auto& dir : dirs) {
                int dx = dir[0], dy = dir[1];
                int nx = x, ny = y;
                int d = stop_position(maze, {x, y}, dir);
                nx += d * dx;
                ny += d * dy;
                if (visited.count(nx * n + ny)) {
                    continue;
                }
                visited.insert(nx * n + ny);
                q.push({nx, ny, distance + d});
            }
        }
        return -1;
    }
};
// @lc code=end
