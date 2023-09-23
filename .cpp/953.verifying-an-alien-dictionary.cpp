/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
// 1. 哈希表
// 2023-09-20 submission
// 125/125 cases passed
// Runtime: 7 ms, faster than 34.85% of cpp online submissions.
// Memory Usage:  MB, less than 12.79% of cpp online submissions.
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        for (int i = 0; i < order.size(); ++i) {
            m[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; ++i) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int j = 0;
            while (j < word1.size() && j < word2.size()) {
                if (word1[j] != word2[j]) {
                    if (m[word1[j]] > m[word2[j]]) {
                        return false;
                    }
                    else {
                        break;
                    }
                }
                ++j;
            }
            if (j == word2.size() && j < word1.size()) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2. 反向替换
// 2023-09-20 submission
// 125/125 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 9.9 MB, less than 17.63% of cpp online submissions.
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> mapping(26);
        for (int i = 0; i < order.size(); ++i) {
            mapping[order[i] - 'a'] = i;
        }
        for (string& word : words) {
            for (char& c : word) {
                c = mapping[c - 'a'];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};
// @lc code=end
