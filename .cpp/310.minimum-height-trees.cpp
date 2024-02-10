/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
// 2020-11-05 submission
// 71/71 cases passed
// Runtime: 151 ms, faster than 96.53% of C++ online submissions.
// Memory Usage: 51.5 MB, less than 91.72% of C++ online submissions.
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int> > graph(n, vector<int>{});
        vector<int> degree(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }

        queue<int> q;
        int cnt = n;
        for (int node = 0; node < n; node++) {
            if (degree[node] <= 1) // < 是为了防止独立点(n=1)的情况
                q.push(node);
        }
        while(cnt > 2) {
            int q_size = q.size();
            cnt -= q_size;
            for (int i = 0; i < q_size; i++) {
                int node = q.front(); q.pop();
                for (int adj : graph[node]) {
                    degree[adj]--;
                    if (degree[adj] == 1) q.push(adj);
                }
            }
        }

        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
// @lc code=end
