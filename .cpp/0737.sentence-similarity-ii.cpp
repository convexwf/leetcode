/*
 * @lc app=leetcode id=737 lang=cpp
 *
 * [737] Sentence Similarity II
 */

// @lc code=start
// 1. 并查集
class Solution {
public:
    string find(string x) {
        if (!parent.count(x)) {
            parent[x] = x;
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(string x, string y) {
        string px = find(x);
        string py = find(y);
        if (px != py) {
            parent[px] = py;
        }
    }

    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2,
                                vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        for (auto& pair : similarPairs) {
            merge(pair[0], pair[1]);
        }
        for (int i = 0; i < sentence1.size(); i++) {
            if (find(sentence1[i]) != find(sentence2[i])) {
                return false;
            }
        }
        return true;
    }

private:
    unordered_map<string, string> parent;
};
// @lc code=end
