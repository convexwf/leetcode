/*
 * @lc app=leetcode id=358 lang=cpp
 *
 * [358] Rearrange String k Distance Apart
 */

// @lc code=start
// 1. 哈希表+最大堆+贪心算法
class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0) return s;
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto& [c, f] : freq) {
            pq.push({f, c});
        }
        string res;
        queue<pair<int, char>> q;
        while (!pq.empty()) {
            auto [f, c] = pq.top();
            pq.pop();
            res += c;
            q.push({f - 1, c});
            if (q.size() >= k) {
                auto [f, c] = q.front();
                q.pop();
                if (f > 0) {
                    pq.push({f, c});
                }
            }
        }
        return res.length() == s.length() ? res : "";
    }
};
// @lc code=end
