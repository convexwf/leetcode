/*
 * @lc app=leetcode id=490 lang=cpp
 *
 * [490] The Maze
 */

// @lc code=start
// 1. bfs
class Solution {
public:
    vector<int> stop_position(vector<vector<int>>& maze, vector<int>& start, vector<int>& dir) {
        int m = maze.size(), n = maze[0].size();
        int x = start[0], y = start[1];
        while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
            x += dir[0];
            y += dir[1];
        }
        x -= dir[0];
        y -= dir[1];
        return {x, y};
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        unordered_set<int> visited;
        queue<vector<int>> q;
        q.push(start);
        visited.insert(start[0] * n + start[1]);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur == destination) {
                return true;
            }
            for (vector<int>& dir : dirs) {
                vector<int> stop = stop_position(maze, cur, dir);
                if (!visited.count(stop[0] * n + stop[1])) {
                    q.push(stop);
                    visited.insert(stop[0] * n + stop[1]);
                }
            }
        }
        return false;
    }
};
// @lc code=end
