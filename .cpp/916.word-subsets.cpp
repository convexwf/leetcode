/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 */

// @lc code=start
// 1. 哈希表
// 2023-09-27 submission
// 56/56 cases passed
// Runtime: 162 ms, faster than 57.14% of cpp online submissions.
// Memory Usage: 102.6 MB, less than 39.54% of cpp online submissions.
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0);
        for (auto& word : words2) {
            vector<int> freq(26, 0);
            for (auto& c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }
        vector<string> res;
        for (auto& word : words1) {
            vector<int> freq(26, 0);
            for (auto& c : word) {
                freq[c - 'a']++;
            }
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(word);
            }
        }
        return res;
    }
};
// @lc code=end
