/*
 * @lc app=leetcode id=2462 lang=cpp
 *
 * [2462] Total Cost to Hire K Workers
 */

// @lc code=start
// 1. 最小堆+双指针
// 2025-03-13 submission
// 162/162 cases passed
// Runtime: 44 ms, faster than 47.02% of cpp online submissions.
// Memory Usage: 75.6 MB, less than 97.84% of cpp online submissions.
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        if (2 * candidates >= n) {
            sort(costs.begin(), costs.end());
            return accumulate(costs.begin(), costs.begin() + k, 0ll);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < candidates; i++) {
            pq.push({costs[i], i});
            pq.push({costs[n - 1 - i], n - 1 - i});
        }
        int l = candidates, r = n - candidates - 1;
        long long ans = 0;
        while (k-- > 0) {
            auto [cost, idx] = pq.top();
            pq.pop();
            ans += cost;
            if (l > r) {
                continue;
            }
            if (idx < l) {
                pq.push({costs[l], l});
                ++l;
            }
            else if (idx > r) {
                pq.push({costs[r], r});
                --r;
            }
        }
        return ans;
    }
};
// @lc code=end
