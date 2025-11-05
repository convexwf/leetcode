/*
 * @lc app=leetcode id=425 lang=cpp
 *
 * [425] Word Squares
 */

// @lc code=start
// 1. 前缀树
class TrieNode {
public:
    vector<TrieNode*> children;
    vector<int> wordIdxs;
    TrieNode() : children(26, nullptr) {
    }
};

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            insert(root, words[i], i);
        }

        vector<string> path;
        vector<vector<string>> res;
        for (int i = 0; i < words.size(); ++i) {
            path.push_back(words[i]);
            dfs(words, root, path, res);
            path.pop_back();
        }

        return res;
    }

    void insert(TrieNode* root, const string& word, int idx) {
        TrieNode* node = root;
        for (const char& c : word) {
            int i = c - 'a';
            if (!node->children[i]) {
                node->children[i] = new TrieNode();
            }
            node = node->children[i];
            node->wordIdxs.push_back(idx);
        }
    }

    void dfs(const vector<string>& words, TrieNode* root, vector<string>& path,
             vector<vector<string>>& res) {
        if (path.size() == path[0].size()) {
            res.push_back(path);
            return;
        }

        int idx = path.size();
        TrieNode* node = root;
        for (int i = 0; i < idx; ++i) {
            int j = path[i][idx] - 'a';
            if (!node->children[j]) {
                return;
            }
            node = node->children[j];
        }

        for (const int& i : node->wordIdxs) {
            path.push_back(words[i]);
            dfs(words, root, path, res);
            path.pop_back();
        }
    }
};
// @lc code=end
