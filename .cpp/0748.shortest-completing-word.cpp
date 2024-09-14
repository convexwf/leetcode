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
        unordered_map<char, int> plate;
        for (char c : licensePlate) {
            if (isalpha(c)) {
                plate[tolower(c)]++;
            }
        }
        string res;
        for (string& word : words) {
            unordered_map<char, int> wordMap;
            for (char c : word) {
                wordMap[c]++;
            }
            bool flag = true;
            for (auto& p : plate) {
                if (wordMap[p.first] < p.second) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (res.empty() || word.size() < res.size()) {
                    res = word;
                }
            }
        }
        return res;
    }
};
// @lc code=end
