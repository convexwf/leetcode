/*
 * @lc app=leetcode id=966 lang=cpp
 *
 * [966] Vowel Spellchecker
 */

// @lc code=start
// 1. 哈希表
// 2023-10-17 submission
// 55/55 cases passed
// Runtime: 68 ms, faster than 59.41% of cpp online submissions.
// Memory Usage: 37.4 MB, less than 52.48% of cpp online submissions.
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap, vowel;
        for (string word : wordlist) {
            string lower = tolow(word);
            string devowel = todevowel(word);
            if (!cap.count(lower)) cap[lower] = word;
            if (!vowel.count(devowel)) vowel[devowel] = word;
        }
        vector<string> ans;
        for (string query : queries) {
            if (words.count(query)) {
                ans.push_back(query);
                continue;
            }
            string lower = tolow(query);
            string devowel = todevowel(query);
            if (cap.count(lower)) {
                ans.push_back(cap[lower]);
            }
            else if (vowel.count(devowel)) {
                ans.push_back(vowel[devowel]);
            }
            else {
                ans.push_back("");
            }
        }
        return ans;
    }
    string tolow(const string& word) {
        string ans;
        for (char c : word) {
            ans.append(1, tolower(c));
        }
        return ans;
    }
    string todevowel(const string& word) {
        string ans = tolow(word);
        for (char& c : ans) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return ans;
    }
};
// @lc code=end
