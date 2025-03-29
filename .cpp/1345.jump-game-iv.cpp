/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */

// @lc code=start
// 1. 哈希表+bfs
// 2023-02-26 submission
// 33/33 cases passed
// Runtime: 210 ms, faster than 81.23% of cpp online submissions.
// Memory Usage: 73.6 MB, less than 70.93% of cpp online submissions.
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            return 0;
        }
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        int step = 0;
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; ++i) {
                int idx = q.front();
                q.pop();
                if (idx == n - 1) {
                    return step;
                }
                if (idx + 1 < n && !visited[idx + 1]) {
                    q.push(idx + 1);
                    visited[idx + 1] = true;
                }
                if (idx - 1 >= 0 && !visited[idx - 1]) {
                    q.push(idx - 1);
                    visited[idx - 1] = true;
                }
                for (int j : mp[arr[idx]]) {
                    if (!visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
                mp[arr[idx]].clear();
            }
            ++step;
        }
        return -1;
    }
};
// @lc code=end
