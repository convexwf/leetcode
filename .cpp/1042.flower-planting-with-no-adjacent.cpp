/*
 * @lc app=leetcode id=1042 lang=cpp
 *
 * [1042] Flower Planting With No Adjacent
 */

// @lc code=start
// 1. 图+邻接表+贪心算法
// 2023-10-23 submission
// 51/51 cases passed
// Runtime: 114 ms, faster than 50.16% of cpp online submissions.
// Memory Usage: 44.1 MB, less than 66.49% of cpp online submissions.
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);
        for (auto& path : paths) {
            graph[path[0] - 1].push_back(path[1] - 1);
            graph[path[1] - 1].push_back(path[0] - 1);
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            vector<bool> used(5, false);
            for (auto& adj : graph[i]) {
                used[ans[adj]] = true;
            }
            for (int j = 1; j <= 4; ++j) {
                if (!used[j]) {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
