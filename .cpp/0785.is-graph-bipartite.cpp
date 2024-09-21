/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
// 1. 并查集
// 2023-02-27 submission
// 81/81 cases passed
// Runtime: 11 ms, faster than 99.98% of cpp online submissions.
// Memory Usage: 13.5 MB, less than 64.18% of cpp online submissions.
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> root(graph.size());
        for (int i = 0; i < graph.size(); ++i) {
            root[i] = i;
        }
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].empty()) continue;
            int x = find(root, i), y = find(root, graph[i][0]);
            if (x == y) return false;
            for (int j = 1; j < graph[i].size(); ++j) {
                int parent = find(root, graph[i][j]);
                if (x == parent) return false;
                root[parent] = y;
            }
        }
        return true;
    }

    int find(vector<int>& root, int i) {
        if (root[i] != i) {
            root[i] = find(root, root[i]);
        }
        return root[i];
    }
};
// @lc code=end

// @lc code=start
// 2. dfs 染色
// 2023-02-27 submission
// 81/81 cases passed
// Runtime: 25 ms, faster than 74.23% of cpp online submissions.
// Memory Usage: 13.5 MB, less than 86.23% of cpp online submissions.
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size());
        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] == 0 && !valid(graph, 1, i, colors)) {
                return false;
            }
        }
        return true;
    }

    bool valid(vector<vector<int>>& graph, int color, int cur, vector<int>& colors) {
        if (colors[cur] != 0) return colors[cur] == color;
        colors[cur] = color;
        for (int i : graph[cur]) {
            if (!valid(graph, -1 * color, i, colors)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 3. bfs 染色
// 2023-02-27 submission
// 81/81 cases passed
// Runtime: 25 ms, faster than 74.23% of cpp online submissions.
// Memory Usage: 13.8 MB, less than 20.15% of cpp online submissions.
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size());
        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] != 0) continue;
            colors[i] = 1;
            queue<int> q{{i}};
            while (!q.empty()) {
                int t = q.front();
                q.pop();
                for (auto a : graph[t]) {
                    if (colors[a] == colors[t]) return false;
                    if (colors[a] == 0) {
                        colors[a] = -1 * colors[t];
                        q.push(a);
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
