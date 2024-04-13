/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
// 1. 并查集
// 2024-01-03 submission
// 75/75 cases passed
// Runtime: 486 ms, faster than 39.13% of cpp online submissions.
// Memory Usage: 159.8 MB, less than 33.42% of cpp online submissions.
class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent, parent[x]);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> parent(n * n, -1);
        unordered_map<int, int> area;
        for (int i = 0; i < n * n; ++i) {
            parent[i] = i;
        }
        // First pass, union find
        for (int idx = 0; idx < n * n; ++idx) {
            int i = idx / n, j = idx % n;
            if (grid[i][j] == 0) {
                continue;
            }
            int up = -1, left = -1;
            if (i > 0 && grid[i - 1][j] == 1) {
                up = find(parent, idx - n);
            }
            if (j > 0 && grid[i][j - 1] == 1) {
                left = find(parent, idx - 1);
            }
            // Condition 1: both up and left are -1, then it is a single island
            if (up == -1 && left == -1) {
                parent[idx] = idx;
                area[idx] = 1;
            }
            // Condition 2: up or left is -1, then it is a connected island up or left
            else if (up == -1 || left == -1) {
                int p = up == -1 ? left : up;
                parent[idx] = p;
                area[p] += 1;
            }
            // Condition 3: the island is connected to different islands
            else if (up != left) {
                parent[left] = idx;
                parent[up] = idx;
                parent[idx] = idx;
                area[idx] = area[up] + area[left] + 1;
            }
            // Condition 4: the island is connected to the same island
            else {
                parent[idx] = up;
                area[up] += 1;
            }
            // cout << i << " " << j << " " << parent[idx] << " " << area[parent[idx]] << endl;
        }
        // Second pass, find max area
        int res = 0;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int idx = 0; idx < n * n; ++idx) {
            int i = idx / n, j = idx % n;
            // Notice that if grid is all 1, then the loop will not be executed
            if (grid[i][j] == 1) {
                continue;
            }
            unordered_set<int> s;
            int area_sum = 1;
            for (auto& dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 0) {
                    continue;
                }
                int p = find(parent, x * n + y);
                if (!s.count(p)) {
                    s.insert(p);
                    area_sum += area[p];
                }
            }
            // cout << "idx " << idx << " area_sum: " << area_sum << endl;
            res = max(res, area_sum);
        }
        return res == 0 ? n * n : res;
    }
};
// @lc code=end
