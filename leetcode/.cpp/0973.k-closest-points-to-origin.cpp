/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
// 1. 自定义排序
// 2023-09-11 submission
// 87/87 cases passed
// Runtime: 179 ms, faster than 74.26% of cpp online submissions.
// Memory Usage: 57.2 MB, less than 94.32% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
// @lc code=end

// @lc code=start
// 2. 最大堆
// 2023-09-11 submission
// 87/87 cases passed
// Runtime: 165 ms, faster than 82.98% of cpp online submissions.
// Memory Usage: 62.4 MB, less than 83.55% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < points.size(); ++i) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (pq.size() < k) {
                pq.push({dist, i});
            }
            else if (dist < pq.top().first) {
                pq.pop();
                pq.push({dist, i});
            }
        }
        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
