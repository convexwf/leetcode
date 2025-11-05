/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 */

// @lc code=start
// 1. 最大堆+贪心算法
// 2024-02-02 submission
// 46/46 cases passed
// Runtime: 23 ms, faster than 95.74% of cpp online submissions.
// Memory Usage: 24.5 MB, less than 34.43% of cpp online submissions.
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers(n);
        for (int i = 0; i < n; i++) {
            workers[i] = {static_cast<double>(wage[i]) / quality[i], quality[i]};
        }
        sort(workers.begin(), workers.end());
        priority_queue<int> pq;
        int sum = 0;
        double ans = DBL_MAX;
        for (int i = 0; i < n; i++) {
            sum += workers[i].second;
            if (pq.size() == k - 1) {
                ans = min(ans, sum * workers[i].first);
            }
            pq.push(workers[i].second);
            if (pq.size() > k - 1) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};
// @lc code=end
