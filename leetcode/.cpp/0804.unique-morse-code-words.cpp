/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */

// @lc code=start
// 1. 哈希表
// 2024-10-16 submission
// 82/82 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 11.6 MB, less than 81.23% of cpp online submissions.
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                                "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                                "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                                "...-", ".--",  "-..-", "-.--", "--.."};
        unordered_set<string> unique;
        for (const string& word : words) {
            string code;
            for (char c : word) {
                code += morse[c - 'a'];
            }
            unique.insert(code);
        }
        return unique.size();
    }
};
// @lc code=end
