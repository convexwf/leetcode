/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
// 1. 哈希表+滑动窗口
// 2020-07-06 submission
// 178/178 cases passed
// Runtime: 200 ms, faster than 73.28% of cpp online submissions.
// Memory Usage: 16.9 MB, less than 90.37% of cpp online submissions.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int n = s.size(), len = words.size(), m = words[0].size();
        unordered_map<string, int> check_freq;
        for (auto& word : words) {
            check_freq[word]++;
        }
        for (int i = 0; i < m; i++) {
            unordered_map<string, int> word_freq = check_freq;
            int left = i;
            for (int pos = i; pos + m <= n; pos += m) {
                string word = s.substr(pos, m);
                --word_freq[word];
                while (word_freq[word] < 0) {
                    ++word_freq[s.substr(left, m)];
                    left += m;
                }
                if (left + len * m == pos + m) {
                    res.push_back(left);
                }
            }
        }
        return res;
    }
};
// @lc code=end
