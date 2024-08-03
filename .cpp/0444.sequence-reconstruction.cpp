/*
 * @lc app=leetcode id=444 lang=cpp
 *
 * [444] Sequence Reconstruction
 */

// @lc code=start
// 1. 拓扑排序
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<vector<int>> graph(n + 1);
        vector<int> inDegree(n + 1);
        for (< vector<int> & seq : seqs) {
            for (int i = 0; i < seq.size(); ++i) {
                if (seq[i] <= 0 || seq[i] > n) return false;
                if (i > 0) {
                    graph[seq[i - 1]].push_back(seq[i]);
                    inDegree[seq[i]]++;
                }
            }
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        int idx = 0;
        while (!q.empty()) {
            if (q.size() > 1) return false;
            int u = q.front();
            q.pop();
            if (idx == n || org[idx++] != u) return false;
            for (int v : graph[u]) {
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return idx == n && idx == org.size();
    }
};
// @lc code=end
