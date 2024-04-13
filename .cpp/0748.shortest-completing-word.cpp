/*
 * @lc app=leetcode id=748 lang=cpp
 *
 * [748] Shortest Completing Word
 */

// @lc code=start
// 1. 哈希表
// 2023-10-11 submission
// 102/102 cases passed
// Runtime: 29 ms, faster than 41.68% of cpp online submissions.
// Memory Usage: 19.8 MB, less than 37.03% of cpp online submissions.
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> license;
        int count = 0;
        for (auto c : licensePlate) {
            if (isalpha(c)) {
                license[tolower(c)]++;
                count++;
            }
        }
        map<int, vector<string>> wordMap;
        for (auto word : words) {
            wordMap[word.size()].push_back(word);
        }
        for (auto& [_, wordList] : wordMap) {
            for (string& word : wordList) {
                unordered_map<char, int> wordCount = license;
                int wordCountSize = 0;
                for (char c : word) {
                    if (wordCount[tolower(c)] > 0) {
                        wordCountSize++;
                    }
                    --wordCount[tolower(c)];
                }
                if (wordCountSize == count) {
                    return word;
                }
            }
        }
        return "";
    }
};
// @lc code=end
