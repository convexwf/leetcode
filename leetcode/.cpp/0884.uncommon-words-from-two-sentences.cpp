/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
// 1. istringstream+哈希表
// 2023-07-18 submission
// 55/55 cases passed
// Runtime: 6 ms, faster than 22.32% of cpp online submissions.
// Memory Usage: 6.8 MB, less than 58.65% of cpp online submissions.
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> cnt;
        istringstream iss(s1 + " " + s2);
        string word;
        while (iss >> word) {
            ++cnt[word];
        }
        vector<string> res;
        for (auto& [word, num] : cnt) {
            if (num == 1) {
                res.push_back(word);
            }
        }
        return res;
    }
};
// @lc code=end
