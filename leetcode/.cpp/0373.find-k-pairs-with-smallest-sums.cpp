/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
// 1. 最大堆+自定义排序
// 2025-02-21 submission
// 30/30 cases passed
// Runtime: 2776 ms, faster than 5.01% of cpp online submissions.
// Memory Usage: 134.3 MB, less than 81.63% of cpp online submissions.
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

// @lc code=start
// 2. 最小堆+自定义排序+优化
// 2025-02-21 submission
// 30/30 cases passed
// Runtime: 35 ms, faster than 91.99% of cpp online submissions.
// Memory Usage: 133.4 MB, less than 93.41% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k <= 0) {
            return res;
        }

        auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < min(k, (int)nums1.size()); ++i) {
            pq.push({i, 0});
        }

        while (k-- > 0 && !pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size()) {
                pq.push({i, j + 1});
            }
        }

        return res;
    }
};
// @lc code=end
