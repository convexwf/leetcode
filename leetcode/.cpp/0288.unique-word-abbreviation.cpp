/*
 * @lc app=leetcode id=288 lang=cpp
 *
 * [288] Unique Word Abbreviation
 */

// @lc code=start
// 1. 哈希表
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (string& word : dictionary) {
            string abbr = getAbbr(word);
            abbr[word].insert(word);
        }
    }

    bool isUnique(string word) {
        string abbr = getAbbr(word);
        return !abbr.count(word) || (abbr[word].size() == 1 && abbr[word].count(word));
    }

private:
    unordered_map<string, unordered_set<string>> abbr;

    string getAbbr(const string& word) {
        if (word.size() <= 2) {
            return word;
        }
        return word.front() + to_string(word.size() - 2) + word.back();
    }
};
// @lc code=end
