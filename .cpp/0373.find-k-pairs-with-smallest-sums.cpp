/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
// 1. 最大堆+自定义排序
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k <= 0) {
            return res;
        }
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first + a.second < b.first + b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < min(k, (int)nums1.size()); ++i) {
            for (int j = 0; j < min(k, (int)nums2.size()); ++j) {
                if (pq.size() < k) {
                    pq.push({nums1[i], nums2[j]});
                }
                else if (nums1[i] + nums2[j] < pq.top().first + pq.top().second) {
                    pq.pop();
                    pq.push({nums1[i], nums2[j]});
                }
            }
        }
        while (!pq.empty()) {
            res.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
