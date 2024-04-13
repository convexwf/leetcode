/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */

// @lc code=start
// 1. 自定义排序+Trie树
// 2023-08-25 submission
// 59/59 cases passed
// Runtime: 24 ms, faster than 99.54% of cpp online submissions.
// Memory Usage: 22.9 MB, less than 72.23% of cpp online submissions.
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            if (a.size() == b.size()) {
                return a < b;
            }
            return a.size() < b.size();
        });
        string res;
        Trie trie;
        for (const string& word : words) {
            if (trie.insert(word)) {
                if (word.size() > res.size()) {
                    res = word;
                }
            }
        }
        return res;
    }

private:
    struct TrieNode
    {
        bool isWord;
        vector<TrieNode*> children;
        TrieNode() : isWord(false), children(26, nullptr) {
        }
    };
    struct Trie
    {
        TrieNode* root;
        Trie() : root(new TrieNode()) {
            root->isWord = true;
        }
        bool insert(const string& word) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->isWord) {
                    return false;
                }
                if (node->children[c - 'a'] == nullptr) {
                    node->children[c - 'a'] = new TrieNode();
                }
                node = node->children[c - 'a'];
            }
            node->isWord = true;
            return true;
        }
    };
};
// @lc code=end

// @lc code=start
// 2. 哈希表+BFS
// 2023-08-25 submission
// 59/59 cases passed
// Runtime: 199 ms, faster than 10.4% of cpp online submissions.
// Memory Usage: 88.7 MB, less than 5.03% of cpp online submissions.
class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> hash;
        for (auto& word : words) {
            hash.insert(word);
        }
        queue<string> q;
        for (auto& word : words) {
            if (word.size() == 1) {
                q.push(word);
            }
        }
        string res;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (cur.size() == res.size()) {
                res = min(res, cur);
            }
            else if (cur.size() > res.size()) {
                res = cur;
            }
            for (char c = 'a'; c <= 'z'; ++c) {
                string tmp = cur + c;
                if (hash.count(tmp)) {
                    q.push(tmp);
                }
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 哈希表+DFS
// 2023-08-25 submission
// 59/59 cases passed
// Runtime: 70 ms, faster than 41.83% of cpp online submissions.
// Memory Usage: 20.7 MB, less than 76.23% of cpp online submissions.
class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        int mxLen = 0;
        unordered_set<string> s(words.begin(), words.end());
        for (string word : words) {
            if (word.size() == 1) helper(s, word, mxLen, res);
        }
        return res;
    }
    void helper(unordered_set<string>& s, string word, int& mxLen, string& res) {
        if (word.size() > mxLen) {
            mxLen = word.size();
            res = word;
        }
        else if (word.size() == mxLen) {
            res = min(res, word);
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            word.push_back(c);
            if (s.count(word)) helper(s, word, mxLen, res);
            word.pop_back();
        }
    }
};
// @lc code=end

// @lc code=start
// 4. 哈希表+贪心
// 2023-08-25 submission
// 59/59 cases passed
// Runtime: 40 ms, faster than 84.91% of cpp online submissions.
// Memory Usage: 18.7 MB, less than 87.89% of cpp online submissions.
class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        unordered_set<string> s;
        sort(words.begin(), words.end());
        for (string word : words) {
            if (word.size() == 1 || s.count(word.substr(0, word.size() - 1))) {
                res = (word.size() > res.size()) ? word : res;
                s.insert(word);
            }
        }
        return res;
    }
};
// @lc code=end
