/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
// 2020-12-13 submission
// 64/64 cases passed
// Runtime: 907 ms, faster than 60.46% of C++ online submissions.
// Memory Usage: 15.6 MB, less than 48.33% of C++ online submissions.
class Solution {
private:
    struct TrieNode {
        TrieNode* child[26];
        string word;
        TrieNode() {
            word = "";
            for (TrieNode*& ptr : child) {
                ptr = NULL;
            }
        }
    };

    struct TrieTree {
        TrieNode* root;
        TrieTree() : root(new TrieNode()) {}
        void insert(string word) {
            TrieNode* cur = root;
            for (char c : word) {
                if (!cur->child[c-'a']) cur->child[c-'a'] = new TrieNode();
                cur = cur->child[c-'a'];
            }
            cur->word = word;
        }
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || board[0].empty()) return vector<string>{};
        vector<string> res;
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        TrieTree* tree = new TrieTree();
        for (string word : words)
            tree->insert(word);

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                DFS(board, visited, res, i, j, tree->root);
            }
        }
        return res;
    }

    void DFS(vector<vector<char>>& board, vector<vector<bool>>& visited, vector<string>& res, int x, int y, TrieNode* cur) {
        if (0 > x || x >= board.size() || 0 > y || y >= board[0].size() || visited[x][y]) return;
        visited[x][y] = true;
        char c = board[x][y];
        if (cur->child[c-'a']) {
            cur = cur->child[c-'a'];
            if (cur->word != "") {
                res.push_back(cur->word);
                cur->word.clear();
            }
            DFS(board, visited, res, x-1, y, cur);
            DFS(board, visited, res, x+1, y, cur);
            DFS(board, visited, res, x, y-1, cur);
            DFS(board, visited, res, x, y+1, cur);
        }
        visited[x][y] = false;
    }
};
// @lc code=end
