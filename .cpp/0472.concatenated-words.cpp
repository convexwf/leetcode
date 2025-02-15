/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */

// @lc code=start
// 1. 自定义排序+前缀树
// 2025-02-12 submission
// 43/43 cases passed
// Runtime: 175 ms, faster than 40.76% of cpp online submissions.
// Memory Usage: 258.1 MB, less than 7.85% of cpp online submissions.
class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode() : children(26, nullptr), isEnd(false) {
    }
};

class Solution {
private:
    TrieNode* root;

public:
    bool isConcatenatedWord(const string& word, int start) {
        TrieNode* cur = root;
        for (int i = start; i < word.size(); ++i) {
            if (!cur->children[word[i] - 'a']) {
                return false;
            }
            cur = cur->children[word[i] - 'a'];
            if (cur->isEnd) {
                if (i == word.size() - 1) {
                    return true;
                }
                if (isConcatenatedWord(word, i + 1)) {
                    return true;
                }
            }
        }
        return false;
    }

    void insert(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new TrieNode();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size() || (a.size() == b.size() && a < b);
        });
        vector<string> res;
        for (const string& word : words) {
            if (isConcatenatedWord(word, 0)) {
                res.push_back(word);
            }
            else {
                insert(word);
            }
        }
        return res;
    }
};
// @lc code=end
