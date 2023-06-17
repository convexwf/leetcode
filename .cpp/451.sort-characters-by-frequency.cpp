/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
// 1. 哈希表+优先队列
// 2023-06-15 submission
// 33/33 cases passed
// Runtime: 12 ms, faster than 72.03% of cpp online submissions.
// Memory Usage: 8.5 MB, less than 52.71% of cpp online submissions.
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            pq.push(make_pair(it->second, it->first));
        }
        string res = "";
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            for (int i = 0; i < p.first; i++) {
                res += p.second;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 哈希表+桶排序
// 2023-06-15 submission
// 33/33 cases passed
// Runtime: 12 ms, faster than 72.03% of cpp online submissions.
// Memory Usage: 15.8 MB, less than 5.05% of cpp online submissions.
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        vector<string> bucket(s.size() + 1, "");
        for (auto& it : freq) {
            bucket[it.second].append(it.second, it.first);
        }
        string ans;
        for (int i = s.size(); i > 0; i--) {
            if (!bucket[i].empty()) {
                ans.append(bucket[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 3. 哈希表+快速排序
// 2023-06-15 submission
// 33/33 cases passed
// Runtime: 279 ms, faster than 5.01% of cpp online submissions.
// Memory Usage: 7.9 MB, less than 96.73% of cpp online submissions.
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (char c : s) ++m[c];
        sort(s.begin(), s.end(),
             [&](char& a, char& b) { return m[a] > m[b] || (m[a] == m[b] && a < b); });
        return s;
    }
};
// @lc code=end