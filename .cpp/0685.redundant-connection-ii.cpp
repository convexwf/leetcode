/*
 * @lc app=leetcode id=685 lang=cpp
 *
 * [685] Redundant Connection II
 */

// @lc code=start
// 1. 并查集
// 2025-06-06 submission
// 57/57 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 13.6 MB, less than 89.3% of cpp online submissions.
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n), parent(n);
        for (const vector<int>& edge : edges) {
            indegree[edge[1] - 1]++;
        }
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        vector<int> candidates;
        for (int i = 0; i < n; ++i) {
            if (indegree[edges[i][1] - 1] == 2) {
                candidates.push_back(i);
            }
        }

        if (!candidates.empty()) {
            for (int i = 0; i < n; ++i) {
                if (i == candidates[1]) continue;
                int pu = find(parent, edges[i][0] - 1);
                int pv = find(parent, edges[i][1] - 1);
                if (pu == pv) {
                    return edges[candidates[0]];
                }
                parent[edges[i][1] - 1] = edges[i][0] - 1;
            }
            return edges[candidates[1]];
        }
        for (int i = 0; i < n; ++i) {
            int pu = find(parent, edges[i][0] - 1);
            int pv = find(parent, edges[i][1] - 1);
            if (pu == pv) {
                return edges[i];
            }
            parent[pu] = pv;
        }
        return {};
    }

    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
};
// @lc code=end
