/*
 * @lc app=leetcode id=676 lang=cpp
 *
 * [676] Implement Magic Dictionary
 */

// @lc code=start
// 1. Brute Force
// 2023-07-10 submission
// 83/83 cases passed
// Runtime: 44 ms, faster than 86.89% of cpp online submissions.
// Memory Usage: 17.9 MB, less than 96.34% of cpp online submissions.
class MagicDictionary {
public:
    MagicDictionary() {
    }

    void buildDict(vector<string> dictionary) {
        dict = dictionary;
    }

    bool search(string searchWord) {
        for (auto& word : dict) {
            if (word.size() != searchWord.size()) continue;
            int cnt = 0;
            for (int i = 0; i < word.size(); ++i) {
                if (word[i] != searchWord[i]) ++cnt;
            }
            if (cnt == 1) return true;
        }
        return false;
    }

private:
    vector<string> dict;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end

// @lc code=start
// 2. 预处理字符串+哈希表
// 2023-07-10 submission
// 83/83 cases passed
// Runtime: 565 ms, faster than 19.81% of cpp online submissions.
// Memory Usage:  MB, less than 16.77% of cpp online submissions.
class MagicDictionary {
private:
    unordered_map<string, unordered_set<string>> dict;
    void replace(string& word, int i) {
        string temp = word;
        temp[i] = '*';
        dict[temp].insert(word);
    }

public:
    /** Initialize your data structure here. */
    MagicDictionary() {
    }

    void buildDict(vector<string> dictionary) {
        for (auto word : dictionary) {
            for (int i = 0; i < word.size(); ++i) {
                replace(word, i);
            }
        }
    }

    bool search(string searchWord) {
        for (int i = 0; i < searchWord.size(); ++i) {
            string temp = searchWord;
            temp[i] = '*';
            if (dict.count(temp)) {
                if (dict[temp].size() > 1 || dict[temp].count(searchWord) == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
