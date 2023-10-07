/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */

// @lc code=start
// 2023-02-26 submission
// 33/33 cases passed
// Runtime: 210 ms, faster than 81.23% of C++ online submissions.
// Memory Usage: 73.6 MB, less than 70.93% of C++ online submissions.
class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (arr.size() <= 1) return 0;

        vector<int> nums;
        unordered_map<int, vector<int>> m;
        int n = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (i == 0 || i == arr.size() - 1 || arr[i] != arr[i - 1] || arr[i] != arr[i+1]) {
                m[arr[i]].push_back(n++);
            }
        }

        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q; q.push(0);
        int step = 0;
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize-- > 0) {
                int idx = q.front(); q.pop();

                for (int neighbor : vector<int>{idx - 1, idx + 1}) {
                    if (neighbor == n - 1) return ++step;
                    if (0 <= neighbor && neighbor < n && !visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }

                vector<int>& neighbors = m[arr[idx]];
                for (int i = (int)neighbors.size() - 1; i >= 0 ; --i) {
                    if (neighbors[i] == n - 1) return ++step;
                    if (!visited[neighbors[i]]) {
                        visited[neighbors[i]] = true;
                        q.push(neighbors[i]);
                    }
                }
                neighbors.clear(); // key operation
            }
            ++step;
        }
        return -1;
    }
};
// @lc code=end
