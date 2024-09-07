/*
 * @lc app=leetcode id=642 lang=cpp
 *
 * [642] Design Search Autocomplete System
 */

// @lc code=start
// 1. 前缀树+自定义排序
class TrieNode {
public:
    TrieNode() {
        for (int i = 0; i < 27; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
        hot = 0;
    }

    TrieNode* children[27];
    bool isEnd;
    int hot;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& sentence, int times) {
        TrieNode* node = root;
        for (char c : sentence) {
            int index = c == ' ' ? 26 : c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
        node->hot += times;
    }

    void search(const string& sentence, vector<pair<string, int>>& res) {
        TrieNode* node = root;
        for (char c : sentence) {
            int index = c == ' ' ? 26 : c - 'a';
            if (node->children[index] == nullptr) {
                return;
            }
            node = node->children[index];
        }
        dfs(sentence, node, res);
    }

private:
    TrieNode* root;

    void dfs(const string& sentence, TrieNode* node, vector<pair<string, int>>& res) {
        if (node->isEnd) {
            res.push_back({sentence, node->hot});
        }
        for (int i = 0; i < 27; i++) {
            if (node->children[i] != nullptr) {
                dfs(sentence + (i == 26 ? " " : string(1, 'a' + i)), node->children[i], res);
            }
        }
    }
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        trie = new Trie();
        for (int i = 0; i < sentences.size(); i++) {
            trie->insert(sentences[i], times[i]);
        }
        inputStr = "";
    }

    vector<string> input(char c) {
        if (c == '#') {
            trie->insert(inputStr, 1);
            inputStr = "";
            return {};
        }
        inputStr.push_back(c);
        vector<string> res;
        trie->search(inputStr, res);
        sort(res.begin(), res.end(), [](const string& a, const string& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });
        vector<string> ans;
        for (int i = 0; i < min(3, (int)res.size()); i++) {
            ans.push_back(res[i].first);
        }
        return ans;
    }

private:
    Trie* trie;
    string inputStr;
};
// @lc code=end
