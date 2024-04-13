/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
// 1. 图+DFS
// 2023-06-20 submission
// 27/27 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.4 MB, less than 20.88% of cpp online submissions.
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, int> var2id;
        int id = 0;
        // 将变量转换为id
        for (const auto& equation : equations) {
            for (const auto& var : equation) {
                if (!var2id.count(var)) {
                    var2id[var] = id++;
                }
            }
        }
        // 构建图，注意是有向图
        // A / B = 2.0 => A -> B = 2.0 & B -> A = 1 / 2.0
        vector<vector<pair<int, double>>> graph(id);
        for (int i = 0; i < equations.size(); ++i) {
            int id1 = var2id[equations[i][0]], id2 = var2id[equations[i][1]];
            graph[id1].emplace_back(id2, values[i]);
            graph[id2].emplace_back(id1, 1.0 / values[i]);
        }
        vector<double> res;
        for (const auto& query : queries) {
            if (!var2id.count(query[0]) || !var2id.count(query[1])) {
                res.emplace_back(-1.0);
            }
            else {
                res.emplace_back(
                    dfs(var2id[query[0]], var2id[query[1]], graph, vector<bool>(id, false)));
            }
        }
        return res;
    }

private:
    double dfs(int src, int dst, const vector<vector<pair<int, double>>>& graph,
               vector<bool> visited) {
        if (src == dst) {
            return 1.0;
        }
        visited[src] = true;
        for (const auto& edge : graph[src]) {
            if (!visited[edge.first]) {
                double res = dfs(edge.first, dst, graph, visited);
                if (res > 0) {
                    return res * edge.second;
                }
            }
        }
        return -1.0;
    }
};
// @lc code=end

// @lc code=start
// 2. 并查集
// 2023-06-20 submission
// 27/27 cases passed
// Runtime: 3 ms, faster than 52.19% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 72.87% of cpp online submissions.
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = equations.size();
        // 初始化并查集
        for (int i = 0; i < n; i++) {
            string a = equations[i][0], b = equations[i][1];
            if (!parent.count(a)) {
                parent[a] = a;
                weight[a] = 1.0;
            }
            if (!parent.count(b)) {
                parent[b] = b;
                weight[b] = 1.0;
            }
            // 合并
            merge(a, b, values[i]);
        }
        // 查询
        vector<double> res;
        for (auto& q : queries) {
            string a = q[0], b = q[1];
            if (!parent.count(a) || !parent.count(b)) {
                res.push_back(-1.0);
                continue;
            }
            string pa = find(a), pb = find(b);
            if (pa != pb) {
                res.push_back(-1.0);
                continue;
            }
            res.push_back(weight[a] / weight[b]);
        }
        return res;
    }

private:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;
    string find(string x) {
        if (x != parent[x]) {
            string origin = parent[x];
            parent[x] = find(parent[x]);
            weight[x] *= weight[origin];
        }
        return parent[x];
    }
    void merge(string a, string b, double val) {
        string pa = find(a), pb = find(b);
        if (pa != pb) {
            parent[pa] = pb;
            weight[pa] = weight[b] * val / weight[a];
        }
    }
};
// @lc code=end
