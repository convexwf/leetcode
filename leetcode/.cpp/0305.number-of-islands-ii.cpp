/*
 * @lc app=leetcode id=305 lang=cpp
 *
 * [305] Number of Islands II
 */

// @lc code=start
// 1. 并查集
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> parent(m * n, -1);
        vector<int> dir = {0, 1, 0, -1, 0};
        vector<int> res;
        for (vector<int>& pos : positions) {
            int x = pos[0], y = pos[1];
            int idx = x * n + y;
            if (parent[idx] != -1) {
                continue;
            }
            parent[idx] = idx;
            ++count;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i], ny = y + dir[i + 1];
                int nidx = nx * n + ny;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || parent[nidx] == -1) {
                    continue;
                }
                if (_union(parent, idx, nidx)) {
                    --count;
                }
            }
            res.push_back(count);
        }
        return res;
    }

    int _find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    bool _union(vector<int>& parent, int x, int y) {
        int px = find(parent, x);
        int py = find(parent, y);
        if (px == py) {
            return false;
        }
        parent[px] = py;
        return true;
    }
};
// @lc code=end
