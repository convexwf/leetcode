/*
 * @lc app=leetcode id=499 lang=cpp
 *
 * [499] The Maze III
 */

// @lc code=start
// 1. bfs
class Solution {
public:
    // 给定一个位置和方向，返回球在该位置以该方向滚动的最终停止位置
    // 停止可能是因为碰到了墙或者到达了洞
    // 返回值为走过的距离
    int stop_position(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole,
                      vector<int>& dir, vector<int>& stop) {
        int m = maze.size(), n = maze[0].size();
        int x = ball[0], y = ball[1];
        int dx = dir[0], dy = dir[1];
        int dist = 0;
        while (x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n &&
               maze[x + dx][y + dy] == 0) {
            x += dx;
            y += dy;
            dist++;
            if (x == hole[0] && y == hole[1]) {
                stop = {x, y};
                return dist;
            }
        }
        stop = {x, y};
        return dist;
    }

    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size();
        unordered_map<char, vector<int>> dirs = {
            {'d', {1, 0}}, {'l', {0, -1}}, {'r', {0, 1}}, {'u', {-1, 0}}};
        vector<char> dir_str = {'d', 'l', 'r', 'u'};
        unordered_set<int> visited;
        queue<pair<vector<int>, string>> q;
        q.push({ball, ""});
        while (!q.empty()) {
            auto [pos, path] = q.front();
            q.pop();
            if (visited.count(pos[0] * n + pos[1])) continue;
            visited.insert(pos[0] * n + pos[1]);
            for (char d : dir_str) {
                vector<int> dir = dirs[d];
                vector<int> stop;
                int dist = stop_position(maze, pos, hole, dir, stop);
                if (dist == 0) continue;
                if (stop[0] == hole[0] && stop[1] == hole[1]) {
                    return path + d;
                }
                q.push({stop, path + d});
            }
        }
        return "impossible";
    }
};
// @lc code=end
