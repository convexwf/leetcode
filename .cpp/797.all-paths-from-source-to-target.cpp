/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
// 1. BFS
// 2023-12-26 submission
// 30/30 cases passed
// Runtime: 16 ms, faster than 42.32% of cpp online submissions.
// Memory Usage: 15.6 MB, less than 36.49% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> path;
        queue<vector<int>> q;
        q.push({0});
        int target = graph.size() - 1;
        while (!q.empty()) {
            vector<int>& cur = q.front();
            if (cur.back() == target) {
                path.push_back(cur);
            }
            else {
                for (int& next : graph[cur.back()]) {
                    cur.push_back(next);
                    q.push(cur);
                    cur.pop_back();
                }
            }
            q.pop();
        }
        return path;
    }
};
// @lc code=end

// @lc code=start
// 2. DFS
// 2023-12-26 submission
// 30/30 cases passed
// Runtime: 11 ms, faster than 65.12% of cpp online submissions.
// Memory Usage: 10.9 MB, less than 98.23% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> path;
        vector<int> current;
        dfs(graph, 0, current, path);
        return path;
    }

    void dfs(vector<vector<int>>& graph, int node, vector<int>& current,
             vector<vector<int>>& path) {
        current.push_back(node);
        if (node == graph.size() - 1) {
            path.push_back(current);
        }
        else {
            for (auto& next : graph[node]) {
                dfs(graph, next, current, path);
            }
        }
        current.pop_back();
    }
};
// @lc code=end
