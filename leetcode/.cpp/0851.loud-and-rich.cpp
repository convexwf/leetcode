/*
 * @lc app=leetcode id=851 lang=cpp
 *
 * [851] Loud and Rich
 */

// @lc code=start
// 1. dfs
// 2024-02-05 submission
// 86/86 cases passed
// Runtime: 80 ms, faster than 83.39% of cpp online submissions.
// Memory Usage:  MB, less than 64.01% of cpp online submissions.
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        for (vector<int>& r : richer) {
            graph[r[1]].push_back(r[0]);
        }
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            dfs(graph, quiet, res, i);
        }
        return res;
    }
    int dfs(vector<vector<int>>& graph, vector<int>& quiet, vector<int>& res, int i) {
        if (res[i] >= 0) return res[i];
        res[i] = i;
        for (int j : graph[i]) {
            int k = dfs(graph, quiet, res, j);
            if (quiet[k] < quiet[res[i]]) {
                res[i] = k;
            }
        }
        return res[i];
    }
};
// @lc code=end
