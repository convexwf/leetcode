/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 */

// @lc code=start
// 1. bfs+位运算
// 2024-02-01 submission
// 35/35 cases passed
// Runtime: 16 ms, faster than 98.26% of cpp online submissions.
// Memory Usage:  MB, less than 84.03% of cpp online submissions.
class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        // find start position and keys
        int start = 0;
        vector<int> key_map(26, -1);
        int k = 0;
        for (int i = 0; i < m * n; ++i) {
            int x = i / n, y = i % n;
            char c = grid[x][y];
            if (c == '@') {
                start = i;
            }
            else if (c >= 'a' && c <= 'z') {
                key_map[c - 'a'] = k++;
            }
        }
        // bfs
        queue<int> q;
        vector<vector<bool>> visited(m * n, vector<bool>(1 << 6, false));
        q.push(start << 6);
        visited[start][0] = true;
        int step = 0;
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize--) {
                int state = q.front();
                q.pop();
                int pos = state >> 6, keys = state & ((1 << 6) - 1);
                for (auto& dir : dirs) {
                    int x = pos / n + dir[0], y = pos % n + dir[1];
                    // out of bound or wall
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#') {
                        continue;
                    }
                    // lock and no key
                    char c = grid[x][y];
                    if (c >= 'A' && c <= 'Z' && !(keys & (1 << key_map[c - 'A']))) {
                        continue;
                    }
                    // check if all keys are collected
                    int newKeys = keys;
                    if (c >= 'a' && c <= 'z') {
                        newKeys |= (1 << key_map[c - 'a']);
                        if (newKeys == (1 << k) - 1) {
                            return step + 1;
                        }
                    }
                    if (!visited[x * n + y][newKeys]) {
                        visited[x * n + y][newKeys] = 1;
                        q.push((x * n + y) << 6 | newKeys);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end
