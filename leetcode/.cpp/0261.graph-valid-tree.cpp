/*
 * @lc app=leetcode id=261 lang=cpp
 *
 * [261] Graph Valid Tree
 */

// @lc code=start
// 1. 并查集
class Solution {
public:
    int _find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    // merge two nodes, return false if they are already in the same connected component
    bool _merge(vector<int>& parent, int x, int y) {
        int rootX = _find(parent, x);
        int rootY = _find(parent, y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
            return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        // merge nodes, return false if there is a cycle
        for (const vector<int>& edge : edges) {
            if (!_merge(parent, edge[0], edge[1])) {
                return false;
            }
        }

        // check if all nodes are in the same connected component
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) {
                ++count;
            }
        }

        return count == 1;
    }
};
// @lc code=end
