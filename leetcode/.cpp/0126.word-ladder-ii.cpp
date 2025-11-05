/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
// 1. BFS + DFS
// 2023-10-02 submission
// 36/36 cases passed
// Runtime: 8 ms, faster than 100% of cpp online submissions.
// Memory Usage: 9.7 MB, less than 38.45% of cpp online submissions.
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Initialize dict
        dict.insert(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) {
            return {};
        }
        dict.erase(beginWord);

        queue<string> q;
        q.push(beginWord);

        bool found = false;
        unordered_set<string> similar;
        while (!q.empty() && !found) {
            // cout << "new level" << endl;
            similar.clear();
            int qsize = q.size();
            while (qsize-- > 0) {
                string word = q.front();
                q.pop();
                findSimilar(word, similar);
            }
            found = similar.count(endWord);
            for (const string& w : similar) {
                dict.erase(w);
                q.push(w);
            }
        }

        vector<vector<string>> res;
        if (found) {
            vector<string> path = {endWord};
            dfs(endWord, beginWord, path, res);
        }
        return res;
    }

private:
    bool isSimilar(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++diff;
            }
            if (diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }

    void findSimilar(const string& word, unordered_set<string>& similar) {
        for (const string& w : dict) {
            if (isSimilar(word, w)) {
                // cout << word << " " << w << endl;
                similar.insert(w);
                parents[w].push_back(word);
            }
        }
    }

    void dfs(const string& word, const string& beginWord, vector<string>& path,
             vector<vector<string>>& res) {
        if (word == beginWord) {
            res.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }
        for (const string& w : parents[word]) {
            path.push_back(w);
            dfs(w, beginWord, path, res);
            path.pop_back();
        }
    }

    unordered_set<string> dict;
    unordered_map<string, vector<string>> parents;
};
// @lc code=end
