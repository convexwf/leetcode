/*
 * @lc app=leetcode id=833 lang=cpp
 *
 * [833] Find And Replace in String
 */

// @lc code=start
// 1. 模拟+哈希表
// 2023-12-27 submission
// 57/57 cases passed
// Runtime: 3 ms, faster than 84.71% of cpp online submissions.
// Memory Usage: 11.4 MB, less than 53.5% of cpp online submissions.
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources,
                             vector<string>& targets) {
        unordered_map<int, pair<int, string>> m;
        for (int i = 0; i < indices.size(); ++i) {
            if (s.substr(indices[i], sources[i].size()) == sources[i]) {
                m[indices[i]] = {sources[i].size(), targets[i]};
            }
        }
        string res;
        for (int i = 0; i < s.size();) {
            if (m.count(i)) {
                res += m[i].second;
                i += m[i].first;
            }
            else {
                res += s[i++];
            }
        }
        return res;
    }
};
// @lc code=end
