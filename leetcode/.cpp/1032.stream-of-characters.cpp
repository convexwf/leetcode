/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 */

// @lc code=start
// 1. 前缀树
// 2024-01-11 submission
// 18/18 cases passed
// Runtime: 125 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 77.83% of cpp online submissions.
struct TrieNode
{
    bool isWord;
    TrieNode* children[26];
    TrieNode() : isWord(false) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class StreamChecker {
private:
    TrieNode* root;
    string queryStr;

public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (auto& word : words) {
            TrieNode* cur = root;
            for (int i = word.size() - 1; i >= 0; --i) {
                int idx = word[i] - 'a';
                if (cur->children[idx] == nullptr) {
                    cur->children[idx] = new TrieNode();
                }
                cur = cur->children[idx];
            }
            cur->isWord = true;
        }
    }

    bool query(char letter) {
        queryStr += letter;
        TrieNode* cur = root;
        for (int i = queryStr.size() - 1; i >= 0; --i) {
            int idx = queryStr[i] - 'a';
            if (cur->children[idx] == nullptr) {
                return false;
            }
            cur = cur->children[idx];
            if (cur->isWord) {
                return true;
            }
        }
        if (queryStr.size() > 200) {
            queryStr = queryStr.substr(queryStr.size() - 200);
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// @lc code=end
