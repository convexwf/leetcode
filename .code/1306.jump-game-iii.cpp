/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// @lc code=start
// 2023-02-24 submission
// 56/56 cases passed
// Runtime: 40 ms, faster than 92.84% of C++ online submissions.
// Memory Usage: 31.3 MB, less than 85.81% of C++ online submissions.
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(start);
        int idx = 0, lp = 0, rp = 0;
        while (!q.empty()) {
            idx = q.front(); q.pop();
            if (arr[idx] == 0) return true;
            lp = idx - arr[idx];
            rp = idx + arr[idx];
            if (lp >= 0 && !visited[lp]) {
                visited[lp] = true;
                q.push(lp);
            }
            if (rp < n && !visited[rp]) {
                visited[rp] = true;
                q.push(rp);
            }
        }
        return false;
    }
};
// @lc code=end
