/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
// 2022-11-14 submission
// 21/21 cases passed
// Runtime: 38 ms, faster than 37.83% of C++ online submissions.
// Memory Usage: 13.6 MB, less than 73.59% of C++ online submissions.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int> > q;
        vector<int> res;
        for (int num : nums)
            {++m[num];}
        for (auto it : m) {
            q.push(make_pair(it.second, it.first));
        }
        for (int i = 0; i < k; i++) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
// @lc code=end