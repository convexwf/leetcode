/*
 * @lc app=leetcode id=269 lang=cpp
 *
 * [269] Alien Dictionary
 */

// @lc code=start
// 1. 拓扑排序
class Solution {
public:
    string alienOrder(vector<string>& words) {
        // Count the number of letters in the words
        vector<bool> alphabet(26, false);
        int count = 0;
        for (const string& word : words) {
            for (char c : word) {
                if (!alphabet[c - 'a']) {
                    alphabet[c - 'a'] = true;
                    ++count;
                }
            }
        }
        // Build the graph
        vector<vector<int>> graph(26, vector<int>(26, 0));
        vector<int> inDegree(26, 0);
        for (int i = 0; i < (int)words.size() - 1; ++i) {
            int j = 0;
            for (; j < words[i].size() && j < words[i + 1].size(); ++j) {
                if (words[i][j] == words[i + 1][j]) {
                    continue;
                }
                if (graph[words[i + 1][j] - 'a'][words[i][j] - 'a'] == 1) {
                    return "";
                }
                graph[words[i][j] - 'a'][words[i + 1][j] - 'a'] = 1;
                ++inDegree[words[i + 1][j] - 'a'];
            }
            if (j == words[i + 1].size() && j < words[i].size()) {
                return "";
            }
        }
        // Topological sort
        queue<int> q;
        string res;
        for (int i = 0; i < 26; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res += u + 'a';
            for (int v = 0; v < 26; ++v) {
                if (graph[u][v] == 1) {
                    --inDegree[v];
                    if (inDegree[v] == 0) {
                        q.push(v);
                    }
                }
            }
        }
        return res.size() == count ? res : "";
    }
};
// @lc code=end
