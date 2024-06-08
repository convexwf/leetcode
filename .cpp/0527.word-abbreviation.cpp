/*
 * @lc app=leetcode id=527 lang=cpp
 *
 * [527] Word Abbreviation
 */

// @lc code=start
// 1. 前缀树
class TrieNode {
public:
    TrieNode() : count(0) {
        children = vector<TrieNode*>(26, nullptr);
    }

    vector<TrieNode*> children;
    int count;
};

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        vector<string> res;
        vector<string> abbrs(words.size());
        vector<int> prefix(words.size(), 1);
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            insert(root, words[i]);
        }
        for (int i = 0; i < words.size(); ++i) {
            string& word = words[i];
            string& abbr = abbrs[i];
            int& pre = prefix[i];
            TrieNode* node = root;
            for (int j = 0; j < word.size(); ++j) {
                node = node->children[word[j] - 'a'];
                if (node->count > 1) {
                    ++pre;
                }
            }
            abbr = word.size() <= 3
                       ? word
                       : word.substr(0, pre) + to_string(word.size() - pre - 1) + word.back();
            res.push_back(abbr.size() < word.size() ? abbr : word);
        }
        return res;
    }

    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
            ++node->count;
        }
    }
};
// @lc code=end
