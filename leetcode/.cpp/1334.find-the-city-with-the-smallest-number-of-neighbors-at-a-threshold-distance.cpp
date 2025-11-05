/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 */

// @lc code=start
// 1. Dijsktra 算法
// 2025-04-07 submission
// 54/54 cases passed
// Runtime: 12 ms, faster than 75.1% of cpp online submissions.
// Memory Usage: 16.5 MB, less than 86.4% of cpp online submissions.
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        for (vector<int>& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int res = -1, minCnt = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) {
                    ++cnt;
                }
            }
            if (cnt <= minCnt) {
                minCnt = cnt;
                res = i;
            }
        }
        return res;
    }
};
// @lc code=end
