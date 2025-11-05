/*
 * @lc app=leetcode id=734 lang=cpp
 *
 * [734] Sentence Similarity
 */

// @lc code=start
// 1. 哈希表
class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2,
                             vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        unordered_map<string, unordered_set<string>> pairs;
        for (const auto& pair : similarPairs) {
            pairs[pair[0]].insert(pair[1]);
            pairs[pair[1]].insert(pair[0]);
        }
        for (int i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] != sentence2[i] && !pairs[sentence1[i]].count(sentence2[i])) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
