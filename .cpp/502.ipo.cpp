/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
// 1. 贪心算法+排序+最大堆
// 2023-11-17 submission
// 35/35 cases passed
// Runtime: 161 ms, faster than 65.33% of cpp online submissions.
// Memory Usage: 82.3 MB, less than 45.69% of cpp online submissions.
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> pq;
        int idx = 0;
        while (k--) {
            while (idx < n && projects[idx].first <= w) {
                pq.push(projects[idx++].second);
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
            else {
                break;
            }
        }
        return w;
    }
};
// @lc code=end
