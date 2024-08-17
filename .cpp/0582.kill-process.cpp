/*
 * @lc app=leetcode id=582 lang=cpp
 *
 * [582] Kill Process
 */

// @lc code=start
// 1. dfs
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < pid.size(); i++) {
            graph[ppid[i]].push_back(pid[i]);
        }
        vector<int> res;
        function<void(int)> dfs = [&](int id) {
            res.push_back(id);
            for (int child : graph[id]) {
                dfs(child);
            }
        };
        dfs(kill);
        return res;
    }
};
// @lc code=end
