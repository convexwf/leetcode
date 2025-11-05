/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start
// 1. dfs
// 2025-03-12 submission
// 39/39 cases passed
// Runtime: 93 ms, faster than 93.13% of cpp online submissions.
// Memory Usage: 127.5 MB, less than 64.78% of cpp online submissions.
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                graph[manager[i]].push_back(i);
            }
        }

        function<int(int)> dfs = [&](int i) {
            int res = 0;
            for (int j : graph[i]) {
                res = max(res, informTime[i] + dfs(j));
            }
            return res;
        };
        return dfs(headID);
    }
};
// @lc code=end
