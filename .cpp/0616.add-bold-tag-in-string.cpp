/*
 * @lc app=leetcode id=616 lang=cpp
 *
 * [616] Add Bold Tag in String
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
    string addBoldTag(string s, vector<string>& words) {
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

        vector<bool> bold(s.size(), false);
        for (int i = 0; i < s.size(); ++i) {
            TrieNode* node = root;
            for (int j = i; j < s.size(); ++j) {
                if (!node->children[s[j] - 'a']) {
                    break;
                }
                node = node->children[s[j] - 'a'];
                if (node->isEnd) {
                    for (int k = i; k <= j; ++k) {
                        bold[k] = true;
                    }
                }
            }
        }

        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (bold[i] && (i == 0 || !bold[i - 1])) {
                res += "<b>";
            }
            res.push_back(s[i]);
            if (bold[i] && (i == s.size() - 1 || !bold[i + 1])) {
                res += "</b>";
            }
        }
        return res;
    }
};
// @lc code=end
