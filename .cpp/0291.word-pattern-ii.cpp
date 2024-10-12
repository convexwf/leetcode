/*
 * @lc app=leetcode id=291 lang=cpp
 *
 * [291] Word Pattern II
 */

// @lc code=start
// 1. 回溯+哈希表
class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char, string> word2ch;
        unordered_map<string, char> ch2word;
        return backtrack(pattern, s, 0, 0, word2ch, ch2word);
    }

    bool backtrack(const string& pattern, const string& s, int i, int j,
                   unordered_map<char, string>& word2ch, unordered_map<string, char>& ch2word) {
        if (i == pattern.size() && j == s.size()) {
            return true;
        }
        if (i == pattern.size() || j == s.size()) {
            return false;
        }
        char ch = pattern[i];
        if (word2ch.count(ch)) {
            string word = word2ch[ch];
            if (j + word.size() > s.size() || s.substr(j, word.size()) != word) {
                return false;
            }
            return backtrack(pattern, s, i + 1, j + word.size(), word2ch, ch2word);
        }
        for (int k = j; k < s.size(); ++k) {
            string word = s.substr(j, k - j + 1);
            if (ch2word.count(word)) {
                continue;
            }
            word2ch[ch] = word;
            ch2word[word] = ch;
            if (backtrack(pattern, s, i + 1, k + 1, word2ch, ch2word)) {
                return true;
            }
            word2ch.erase(ch);
            ch2word.erase(word);
        }
        return false;
    }
};
// @lc code=end
