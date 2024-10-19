/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

// @lc code=start
// 1, 哈希表
// 2023-08-16 submission
// 48/48 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.7 MB, less than 43.21% of cpp online submissions.
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> wordCount;
        string word;
        paragraph += ".";
        for (char& c : paragraph) {
            if (isalpha(c)) {
                word += tolower(c);
            }
            else if (!word.empty()) {
                if (!bannedSet.count(word)) {
                    wordCount[word]++;
                }
                word.clear();
            }
        }
        string res;
        int maxCount = 0;
        for (auto& [w, c] : wordCount) {
            if (c > maxCount) {
                maxCount = c;
                res = w;
            }
        }
        return res;
    }
};
// @lc code=end
