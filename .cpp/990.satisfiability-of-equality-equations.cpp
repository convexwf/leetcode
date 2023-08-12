/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 */

// @lc code=start
// 1. 并查集
// 2023-08-09 submission
// 181/181 cases passed
// Runtime: 3 ms, faster than 92.25% of cpp online submissions.
// Memory Usage: 11.3 MB, less than 79.93% of cpp online submissions.
class UnionFind {
private:
    vector<int> parent;

public:
    UnionFind() {
        parent.resize(26);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int index) {
        if (index == parent[index]) {
            return index;
        }
        parent[index] = find(parent[index]);
        return parent[index];
    }
    void unite(int index1, int index2) {
        parent[find(index1)] = find(index2);
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf;
        for (const string& str : equations) {
            if (str[1] == '=') {
                int index1 = str[0] - 'a';
                int index2 = str[3] - 'a';
                uf.unite(index1, index2);
            }
        }
        for (const string& str : equations) {
            if (str[1] == '!') {
                int index1 = str[0] - 'a';
                int index2 = str[3] - 'a';
                if (uf.find(index1) == uf.find(index2)) {
                    return false;
                }
            }
        }
        return true;
    }
};
// class Solution {
// public:
//     bool equationsPossible(vector<string>& equations) {
//         vector<int> root(26);
//         for (int i = 0; i < 26; ++i) root[i] = i;
//         for (string eq : equations) {
//             if (eq[1] == '!') continue;
//             root[find(root, eq[0] - 'a')] = find(root, eq[3] - 'a');
//         }
//         for (string eq : equations) {
//             if (eq[1] == '=') continue;
//             if (find(root, eq[0] - 'a') == find(root, eq[3] - 'a')) return false;
//         }
//         return true;
//     }
//     int find(vector<int>& root, int x) {
//         return root[x] == x ? x : find(root, root[x]);
//     }
// };
// @lc code=end

// @lc code=start
// 2. DFS
// 2023-08-09 submission
// 181/181 cases passed
// Runtime: 4 ms, faster than 86.09% of cpp online submissions.
// Memory Usage: 11.6 MB, less than 25.72% of cpp online submissions.
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>> graph(26);
        for (const string& str : equations) {
            if (str[1] == '=') {
                int x = str[0] - 'a';
                int y = str[3] - 'a';
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
        }
        vector<bool> visited(26, false);
        for (const string& str : equations) {
            if (str[1] == '!') {
                fill(visited.begin(), visited.end(), false);
                int x = str[0] - 'a';
                int y = str[3] - 'a';
                if (DFS(graph, visited, x, y)) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool DFS(vector<vector<int>>& graph, vector<bool>& visited, int x, int y) {
        if (x == y) {
            return true;
        }
        visited[x] = true;
        for (int i = 0; i < graph[x].size(); ++i) {
            if (!visited[graph[x][i]]) {
                if (DFS(graph, visited, graph[x][i], y)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
