/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
// 1. 前缀树+dfs
// 2020-12-01 submission
// 29/29 cases passed
// Runtime: 889 ms, faster than 95.07% of cpp online submissions.
// Memory Usage: 558.4 MB, less than 75.25% of cpp online submissions.
class WordDictionary {
public:
    struct TrieNode
    {
        bool is_word;
        vector<TrieNode*> children;
        TrieNode() : is_word(false), children(26, nullptr) {
        }
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->is_word = true;
    }

    // Returns if the word is in the data structure. A word could contain the dot character '.' to
    // represent any one letter.
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(const string& word, int index, TrieNode* node) {
        if (node == nullptr) {
            return false;
        }
        if (index == word.size()) {
            return node->is_word;
        }
        char c = word[index];
        if (c != '.') {
            return dfs(word, index + 1, node->children[c - 'a']);
        }
        else {
            for (TrieNode* child : node->children) {
                if (dfs(word, index + 1, child)) {
                    return true;
                }
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
