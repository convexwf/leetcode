/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
// 1. DFS
// 2023-10-10 submission
// 112/112 cases passed
// Runtime: 107 ms, faster than 96.14% of cpp online submissions.
// Memory Usage: 47.5 MB, less than 85.12% of cpp online submissions.
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (dfs(graph, color, i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    bool dfs(vector<vector<int>>& graph, vector<int>& color, int cur) {
        if (color[cur] > 0) {
            return color[cur] == 2;
        }
        color[cur] = 1;
        for (int next : graph[cur]) {
            if (!dfs(graph, color, next)) {
                return false;
            }
        }
        color[cur] = 2;
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2. 拓扑排序
// 2023-10-10 submission
// 112/112 cases passed
// Runtime: 164 ms, faster than 31.78% of cpp online submissions.
// Memory Usage:  MB, less than 16.54% of cpp online submissions.
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n);
        vector<vector<int>> reverseGraph(n);
        for (int i = 0; i < n; i++) {
            outdegree[i] = graph[i].size();
            for (int j = 0; j < graph[i].size(); j++) {
                reverseGraph[graph[i][j]].push_back(i);
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < reverseGraph[cur].size(); i++) {
                int next = reverseGraph[cur][i];
                outdegree[next]--;
                if (outdegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end
