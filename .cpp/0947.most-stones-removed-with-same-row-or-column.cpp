/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
// 1. 并查集
// 2024-01-04 submission
// 69/69 cases passed
// Runtime: 176 ms, faster than 35.84% of cpp online submissions.
// Memory Usage: 14.5 MB, less than 95.07% of cpp online submissions.
class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent, parent[x]);
    }

    void _union(vector<int>& parent, int x, int y) {
        int px = find(parent, x);
        int py = find(parent, y);
        if (px != py) {
            parent[px] = py;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    _union(parent, i, j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) {
                ++cnt;
            }
        }
        return n - cnt;
    }
};
// @lc code=end
