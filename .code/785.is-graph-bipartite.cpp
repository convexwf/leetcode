/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 *
 * https://leetcode.com/problems/is-graph-bipartite/description/
 *
 * algorithms
 * Medium (53.02%)
 * Likes:    6168
 * Dislikes: 299
 * Total Accepted:    388K
 * Total Submissions: 731.7K
 * Testcase Example:  '[[1,2,3],[0,2],[0,1,3],[0,2]]'
 *
 * There is an undirected graph with n nodes, where each node is numbered
 * between 0 and n - 1. You are given a 2D array graph, where graph[u] is an
 * array of nodes that node u is adjacent to. More formally, for each v in
 * graph[u], there is an undirected edge between node u and node v. The graph
 * has the following properties:
 *
 *
 * There are no self-edges (graph[u] does not contain u).
 * There are no parallel edges (graph[u] does not contain duplicate
 * values).
 * If v is in graph[u], then u is in graph[v] (the graph is undirected).
 * The graph may not be connected, meaning there may be two nodes u and v such
 * that there is no path between them.
 *
 *
 * A graph is bipartite if the nodes can be partitioned into two independent
 * sets A and B such that every edge in the graph connects a node in set A and
 * a node in set B.
 *
 * Return true if and only if it is bipartite.
 *
 *
 * Example 1:
 *
 *
 * Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
 * Output: false
 * Explanation: There is no way to partition the nodes into two independent
 * sets such that every edge connects a node in one and a node in the other.
 *
 * Example 2:
 *
 *
 * Input: graph = [[1,3],[0,2],[1,3],[0,2]]
 * Output: true
 * Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 *
 *
 * Constraints:
 *
 *
 * graph.length == n
 * 1 <= n <= 100
 * 0 <= graph[u].length < n
 * 0 <= graph[u][i] <= n - 1
 * graph[u] does not contain u.
 * All the values of graph[u] are unique.
 * If graph[u] contains v, then graph[v] contains u.
 *
 *
 */

// @lc code=start
// 2023-02-27 submission
// 81/81 cases passed
// Runtime: 11 ms, faster than 99.98% of C++ online submissions.
// Memory Usage: 13.5 MB, less than 64.18% of C++ online submissions.
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> root(graph.size());
        for (int i = 0; i < graph.size(); ++i) root[i] = i;
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
        return root[i] == i ? i : find(root, root[i]);
    }
};
// @lc code=end

// @lc code=start
// 2023-02-27 submission
// 81/81 cases passed
// Runtime: 25 ms, faster than 74.23% of C++ online submissions.
// Memory Usage: 13.5 MB, less than 86.23% of C++ online submissions.
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
    bool valid(vector<vector<int>>& graph, int color, int cur,
               vector<int>& colors) {
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
// 2023-02-27 submission
// 81/81 cases passed
// Runtime: 25 ms, faster than 74.23% of C++ online submissions.
// Memory Usage: 13.8 MB, less than 20.15% of C++ online submissions.
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
