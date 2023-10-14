/*
 * @lc app=leetcode id=1078 lang=cpp
 *
 * [1078] Occurrences After Bigram
 */

// @lc code=start
// 1. 字符串处理
// 2023-10-08 submission
// 30/30 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.2 MB, less than 6.52% of cpp online submissions.
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        vector<string> words;
        string word;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                words.push_back(word);
                word = "";
            }
            else {
                word += text[i];
            }
        }
        words.push_back(word);
        for (int i = 0; i < words.size() - 2; i++) {
            if (words[i] == first && words[i + 1] == second) {
                res.push_back(words[i + 2]);
            }
        }
        return res;
    }
};
// @lc code=end
