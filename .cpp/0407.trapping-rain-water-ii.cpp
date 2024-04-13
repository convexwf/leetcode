/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */

// @lc code=start
// 1. 优先队列+BFS
// 2023-05-22 submission
// 42/42 cases passed
// Runtime: 74 ms, faster than 81.78% of cpp online submissions.
// Memory Usage: 12.8 MB, less than 97.49% of cpp online submissions.
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // 将四周的点加入优先队列
        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], i * n});
            pq.push({heightMap[i][n - 1], i * n + n - 1});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j) {
            pq.push({heightMap[0][j], j});
            pq.push({heightMap[m - 1][j], (m - 1) * n + j});
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        // 遍历优先队列
        int res = 0;
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int h = t.first;
            int r = t.second / n;
            int c = t.second % n;
            // 将当前点四周的点加入队列
            if (r > 0 && !visited[r - 1][c]) {
                res += max(0, h - heightMap[r - 1][c]);
                pq.push({max(h, heightMap[r - 1][c]), (r - 1) * n + c});
                visited[r - 1][c] = true;
            }
            if (r < m - 1 && !visited[r + 1][c]) {
                res += max(0, h - heightMap[r + 1][c]);
                pq.push({max(h, heightMap[r + 1][c]), (r + 1) * n + c});
                visited[r + 1][c] = true;
            }
            if (c > 0 && !visited[r][c - 1]) {
                res += max(0, h - heightMap[r][c - 1]);
                pq.push({max(h, heightMap[r][c - 1]), r * n + c - 1});
                visited[r][c - 1] = true;
            }
            if (c < n - 1 && !visited[r][c + 1]) {
                res += max(0, h - heightMap[r][c + 1]);
                pq.push({max(h, heightMap[r][c + 1]), r * n + c + 1});
                visited[r][c + 1] = true;
            }
        }
        return res;
    }
};
// @lc code=end
