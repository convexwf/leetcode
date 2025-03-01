/*
 * @lc app=leetcode id=675 lang=cpp
 *
 * [675] Cut Off Trees for Golf Event
 */

// @lc code=start
// 1. BFS
// 2024-01-23 submission
// 55/55 cases passed
// Runtime: 842 ms, faster than 76.38% of cpp online submissions.
// Memory Usage: 114.4 MB, less than 77.35% of cpp online submissions.
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        rows = m;
        cols = n;
        vector<vector<int>> trees;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) {
                    trees.push_back({forest[i][j], i, j});
                }
            }
        }
        sort(trees.begin(), trees.end());
        int ans = 0, x = 0, y = 0;
        for (const vector<int>& tree : trees) {
            int step = bfs(forest, x, y, tree[1], tree[2]);
            if (step == -1) {
                return -1;
            }
            ans += step;
            x = tree[1];
            y = tree[2];
        }
        return ans;
    }

    int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        int m = forest.size(), n = forest[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<int> q;
        q.push(sx * cols + sy);
        visited[sx][sy] = true;
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int cur = q.front();
                q.pop();
                int x = cur / cols;
                int y = cur % cols;
                if (x == tx && y == ty) {
                    return step;
                }
                for (const vector<int>& dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny] ||
                        forest[nx][ny] == 0) {
                        continue;
                    }
                    q.push(nx * cols + ny);
                    visited[nx][ny] = true;
                }
            }
            ++step;
        }
        return -1;
    }

private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows;
    int cols;
};
// @lc code=end

// @lc code=start
// 2. A* 算法(BFS+优先队列)
// 2024-01-23 submission
// 55/55 cases passed
// Runtime: 630 ms, faster than 86.73% of cpp online submissions.
// Memory Usage: 118.8 MB, less than 74.11% of cpp online submissions.
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> trees;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) {
                    trees.push_back({forest[i][j], i * n + j});
                }
            }
        }
        sort(trees.begin(), trees.end());
        int ans = 0;
        int start = 0;
        for (int i = 0; i < trees.size(); ++i) {
            int step = bfs(forest, start, trees[i][1]);
            if (step == -1) {
                return -1;
            }
            ans += step;
            start = trees[i][1];
        }
        return ans;
    }

private:
    // Calculate the Manhattan distance between two points
    int f(int start, int end, int n) {
        int x1 = start / n, y1 = start % n;
        int x2 = end / n, y2 = end % n;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int bfs(vector<vector<int>>& forest, int start, int end) {
        int m = forest.size(), n = forest[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(m * n, INT_MAX);
        pq.push({f(start, end, n), start});
        dist[start] = 0;
        while (!pq.empty()) {
            auto [_, cur] = pq.top();
            pq.pop();
            if (cur == end) {
                return dist[cur];
            }
            int x = cur / n, y = cur % n;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || forest[nx][ny] == 0) {
                    continue;
                }
                int next = nx * n + ny;
                if (dist[next] > dist[cur] + 1) {
                    dist[next] = dist[cur] + 1;
                    pq.push({dist[next] + f(next, end, n), next});
                }
            }
        }
        return -1;
    }

    vector<int> dirs = {-1, 0, 1, 0, -1};
};
// @lc code=end
