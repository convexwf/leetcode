/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
// 1. 哈希表+最小堆+自定义排序
// 2023-11-08 submission
// 110/110 cases passed
// Runtime: 7 ms, faster than 91.14% of cpp online submissions.
// Memory Usage: 12.8 MB, less than 80.23% of cpp online submissions.
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string& word : words) {
            ++freq[word];
        }
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        for (auto& [word, count] : freq) {
            pq.emplace(word, count);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 2. 桶排序
// 2023-11-08 submission
// 110/110 cases passed
// Runtime: 7 ms, faster than 91.14% of cpp online submissions.
// Memory Usage:  MB, less than 6.51% of cpp online submissions.
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string& word : words) {
            freq[word]++;
        }
        vector<set<string>> buckets(words.size() + 1);
        for (auto& p : freq) {
            buckets[p.second].insert(p.first);
        }
        vector<string> res;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (auto& word : buckets[i]) {
                res.push_back(word);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
// @lc code=end
