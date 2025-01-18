/*
 * @lc app=leetcode id=745 lang=cpp
 *
 * [745] Prefix and Suffix Search
 */

// @lc code=start
// 1. 哈希表
// 2023-12-25 submission
// 17/17 cases passed
// Runtime: 1882 ms, faster than 6.34% of cpp online submissions.
// Memory Usage: 401.8 MB, less than 53.66% of cpp online submissions.
class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            for (int j = 0; j <= word.size(); ++j) {
                for (int k = 0; k <= word.size(); ++k) {
                    string key = word.substr(0, j) + "#" + word.substr(word.size() - k);
                    m[key].push_back(i);
                }
            }
        }
    }

    int f(string pref, string suff) {
        string key = pref + "#" + suff;
        if (m[key].empty()) {
            return -1;
        }
        else {
            return m[key].back();
        }
    }

private:
    unordered_map<string, vector<int>> m;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
// @lc code=end

// @lc code=start
// 2. 双哈希表
// 2023-12-25 submission
// 17/17 cases passed
// Runtime: 751 ms, faster than 59.02% of cpp online submissions.
// Memory Usage: 185.5 MB, less than 97.56% of cpp online submissions.
class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            for (int j = 0; j <= word.size(); ++j) {
                string prefix = word.substr(0, j);
                prefix2Index[prefix].push_back(i);
            }
            for (int j = 0; j <= word.size(); ++j) {
                string suffix = word.substr(j);
                suffix2Index[suffix].push_back(i);
            }
        }
    }

    int f(string prefix, string suffix) {
        if (!prefix2Index.count(prefix) || !suffix2Index.count(suffix)) {
            return -1;
        }
        int i = prefix2Index[prefix].size() - 1;
        int j = suffix2Index[suffix].size() - 1;
        while (i >= 0 && j >= 0) {
            if (prefix2Index[prefix][i] < suffix2Index[suffix][j]) {
                --j;
            }
            else if (prefix2Index[prefix][i] > suffix2Index[suffix][j]) {
                --i;
            }
            else {
                return prefix2Index[prefix][i];
            }
        }
        return -1;
    }

private:
    unordered_map<string, vector<int>> prefix2Index;
    unordered_map<string, vector<int>> suffix2Index;
};
// @lc code=end
