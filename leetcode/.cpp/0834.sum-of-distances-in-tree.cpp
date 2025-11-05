/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

// @lc code=start
// 1. dfs
// 2025-03-10 submission
// 74/74 cases passed
// Runtime: 343 ms, faster than 5.14% of cpp online submissions.
// Memory Usage: 102.7 MB, less than 53.19% of cpp online submissions.
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (const vector<int>& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> count(n), dist(n);
        function<void(int, int)> dfs1 = [&](int node, int parent) {
            count[node] = 1;
            for (int child : graph[node]) {
                if (child == parent) {
                    continue;
                }
                dfs1(child, node);
                count[node] += count[child];
                dist[node] += dist[child] + count[child];
            }
        };
        dfs1(0, -1);

        function<void(int, int)> dfs2 = [&](int node, int parent) {
            for (int child : graph[node]) {
                if (child == parent) {
                    continue;
                }
                dist[child] = dist[node] - count[child] + n - count[child];
                dfs2(child, node);
            }
        };
        dfs2(0, -1);
        return dist;
    }
};
// @lc code=end
