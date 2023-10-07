/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
// 2022-11-14 submission
// 16/16 cases passed
// Runtime: 176 ms, faster than 24.53% of C++ online submissions.
// Memory Usage: 44.9 MB, less than 70.49% of C++ online submissions.
class Node{
public:
    Node* child[26];
    bool is_word;
    Node() {
        is_word = false;
        for (Node*& ptr : child) {
            ptr = NULL;
        }
    }
};

class Trie {
public:
    Node* root;

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        for (int i = 0; i < word.length(); i++) {
            if(!cur->child[word[i]-'a']) {
                cur->child[word[i]-'a'] = new Node();
            }
            cur = cur->child[word[i]-'a'];
        }
        cur->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        for (int i = 0; i < word.length(); i++) {
            if(!cur->child[word[i]-'a']) return false;
            cur = cur->child[word[i]-'a'];
        }
        return cur->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        for (int i = 0; i < prefix.length(); i++) {
            if(!cur->child[prefix[i]-'a']) return false;
            cur = cur->child[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
