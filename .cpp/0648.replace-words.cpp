/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

// @lc code=start
// 1. Trie 树
// 2023-06-28 submission
// 127/127 cases passed
// Runtime: 106 ms, faster than 67.08% of cpp online submissions.
// Memory Usage: 77.7 MB, less than 37.22% of cpp online submissions.
class Trie {
public:
    Trie() : root_(new TrieNode()) {
    }

    void insert(const string& word) {
        TrieNode* cur = root_;
        for (const char c : word) {
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->is_word = true;
    }

    string getShortestPrefix(const string& word) {
        TrieNode* cur = root_;
        string prefix;
        for (const char c : word) {
            prefix += c;
            if (cur->children[c - 'a'] == nullptr) {
                return word;
            }
            cur = cur->children[c - 'a'];
            if (cur->is_word) {
                return prefix;
            }
        }
        return word;
    }

private:
    struct TrieNode
    {
        TrieNode() : is_word(false), children(26, nullptr) {
        }

        ~TrieNode() {
            for (TrieNode* child : children) {
                if (child != nullptr) {
                    delete child;
                }
            }
        }

        bool is_word;
        vector<TrieNode*> children;
    };
    TrieNode* root_;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string& word : dictionary) {
            trie.insert(word);
        }

        string res;
        string word;
        istringstream iss(sentence);
        while (iss >> word) {
            res += trie.getShortestPrefix(word) + " ";
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 哈希集合
// 2023-06-28 submission
// 127/127 cases passed
// Runtime: 905 ms, faster than 19.3% of cpp online submissions.
// Memory Usage: 477.3 MB, less than 8.74% of cpp online submissions.
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict;
        for (const string& word : dictionary) {
            dict.insert(word);
        }
        string res;
        string word;
        istringstream iss(sentence);
        while (iss >> word) {
            string prefix;
            for (int i = 1; i <= word.size(); ++i) {
                prefix = word.substr(0, i);
                if (dict.count(prefix)) {
                    break;
                }
            }
            res += prefix + " ";
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 排序
// 2023-06-28 submission
// 127/127 cases passed
// Runtime: 712 ms, faster than 23.89% of cpp online submissions.
// Memory Usage: 336.9 MB, less than 17.92% of cpp online submissions.
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(), dictionary.end(),
             [](const string& a, const string& b) { return a.size() < b.size(); });
        string res;
        istringstream iss(sentence);
        string word;
        while (iss >> word) {
            for (const string& root : dictionary) {
                if (word.substr(0, root.size()) == root) {
                    word = root;
                    break;
                }
            }
            res += word + " ";
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end