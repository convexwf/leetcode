/*
 * @lc app=leetcode id=1057 lang=cpp
 *
 * [1057] Campus Bikes
 */

// @lc code=start
// 1. 排序
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<pair<int, pair<int, int>>> dis;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                dis.push_back({d, {i, j}});
            }
        }
        sort(dis.begin(), dis.end());
        vector<int> ans(n, -1), used(m, 0);
        for (int i = 0; i < dis.size(); ++i) {
            int w = dis[i].second.first, b = dis[i].second.second;
            if (ans[w] == -1 && !used[b]) {
                ans[w] = b;
                used[b] = 1;
            }
        }
        return ans;
    }
};
// @lc code=end
