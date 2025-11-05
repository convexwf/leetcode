/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
// 1. 哈希表
// 2024-05-28 submission
// 43/43 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.8 MB, less than 41.14% of cpp online submissions.
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> word2ch;
        unordered_map<char, string> ch2word;
        vector<string> words;
        string word;
        istringstream in(s);
        while (in >> word) {
            words.push_back(word);
        }
        if (pattern.size() != words.size()) {
            return false;
        }
        for (int i = 0; i < pattern.size(); ++i) {
            char ch = pattern[i];
            string word = words[i];
            if (word2ch.count(word) && word2ch[word] != ch ||
                ch2word.count(ch) && ch2word[ch] != word) {
                return false;
            }
            word2ch[word] = ch;
            ch2word[ch] = word;
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 1. 哈希表
// 2022-11-14 submission
// 37/37 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.3 MB, less than 83.62% of cpp online submissions.
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream in(str);
        int i = 0, n = pattern.length();
        for (string word; in >> word; ++i) {
            if (i >= n || m1[pattern[i]] != m2[word]) return false; // i>=n 表示 p 长度比 s 短
            m1[pattern[i]] = m2[word] = i + 1;
        }
        return i == n; // s 已经遍历完，如果 i!=n(i<n) 表示 p 长度比 s 长
    }
};
// @lc code=end
