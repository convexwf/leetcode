/*
 * @lc app=leetcode id=1065 lang=cpp
 *
 * [1065] Index Pairs of a String
 */

// @lc code=start
// 1. 前缀树
class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode() : children(26, nullptr), isEnd(false) {
    }
};

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children[c - 'a']) {
                    node->children[c - 'a'] = new TrieNode();
                }
                node = node->children[c - 'a'];
            }
            node->isEnd = true;
        }
        vector<vector<int>> res;
        for (int i = 0; i < text.size(); ++i) {
            TrieNode* node = root;
            for (int j = i; j < text.size(); ++j) {
                if (!node->children[text[j] - 'a']) {
                    break;
                }
                node = node->children[text[j] - 'a'];
                if (node->isEnd) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
// @lc code=end
