/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
// 1. 哈希表+最小堆
// 2022-11-14 submission
// 21/21 cases passed
// Runtime: 9 ms, faster than 78.68% of cpp online submissions.
// Memory Usage: 17.2 MB, less than 60.27% of cpp online submissions.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (auto& [num, count] : freq) {
            if (pq.size() < k) {
                pq.push({num, count});
            }
            else {
                if (pq.top().second < count) {
                    pq.pop();
                    pq.push({num, count});
                }
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};
// @lc code=end
