/*
 * @lc app=leetcode id=588 lang=cpp
 *
 * [588] Design In-Memory File System
 */

// @lc code=start
// 1. 前缀树+哈希表
class FileSystem {
public:
    struct TrieNode
    {
        bool isFile = false;
        string content = "";
        unordered_map<string, TrieNode*> children;
    };

    FileSystem() {
        root = new TrieNode();
    }

    vector<string> ls(string path) {
        TrieNode* node = root;
        vector<string> dirs = split(path, '/');
        for (string dir : dirs) {
            if (dir.empty()) {
                continue;
            }
            if (!node->children.count(dir)) {
                return {};
            }
            node = node->children[dir];
        }
        if (node->isFile) {
            return {dirs.back()};
        }
        vector<string> res;
        for (auto& p : node->children) {
            res.push_back(p.first);
        }
        sort(res.begin(), res.end());
        return res;
    }

    void mkdir(string path) {
        TrieNode* node = root;
        vector<string> dirs = split(path, '/');
        for (string dir : dirs) {
            if (dir.empty()) {
                continue;
            }
            if (!node->children.count(dir)) {
                node->children[dir] = new TrieNode();
            }
            node = node->children[dir];
        }
    }

    void addContentToFile(string filePath, string content) {
        TrieNode* node = root;
        vector<string> dirs = split(filePath, '/');
        for (string dir : dirs) {
            if (dir.empty()) {
                continue;
            }
            if (!node->children.count(dir)) {
                node->children[dir] = new TrieNode();
            }
            node = node->children[dir];
        }
        node->isFile = true;
        node->content += content;
    }

    string readContentFromFile(string filePath) {
        TrieNode* node = root;
        vector<string> dirs = split(filePath, '/');
        for (string dir : dirs) {
            if (dir.empty()) {
                continue;
            }
            if (!node->children.count(dir)) {
                return "";
            }
            node = node->children[dir];
        }
        return node->content;
    }

    vector<string> split(const string& path, const char& c) {
        vector<string> res;
        string s = "";
        for (char ch : path) {
            if (ch == c) {
                res.push_back(s);
                s = "";
            }
            else {
                s += ch;
            }
        }
        res.push_back(s);
        return res;
    }

private:
    TrieNode* root;
};
// @lc code=end
