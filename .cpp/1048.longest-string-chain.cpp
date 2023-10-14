/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
// 1. 自定义排序+哈希表
// 2023-10-09 submission
// 85/85 cases passed
// Runtime: 154 ms, faster than 24.79% of cpp online submissions.
// Memory Usage: 51.3 MB, less than 35.24% of cpp online submissions.
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // 自定义排序
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size() || (a.size() == b.size() && a < b);
        });
        // 哈希表
        unordered_map<string, int> m;
        int res = 0;
        for (auto& word : words) {
            for (int i = 0; i < word.size(); ++i) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                // 如果没找到 predecessor，那么 m[word] = 1
                m[word] = max(m[word], m[predecessor] + 1);
            }
            res = max(res, m[word]);
        }
        return res;
    }
};
// @lc code=end
