/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
// 2023-01-14 submission
// 26/26 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 7.5 MB, less than 28.54% of C++ online submissions.
class Solution {
public:
    unordered_map<string, vector<string>> m;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (m.count(s)) return m[s];
        if (s.empty()) return {""};
        vector<string> res;
        for (string word : wordDict) {
            if (s.substr(0, word.size()) != word) continue;
            vector<string> rem = wordBreak(s.substr(word.size()), wordDict);
            for (string str : rem) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return m[s] = res;
    }
};
// @lc code=end