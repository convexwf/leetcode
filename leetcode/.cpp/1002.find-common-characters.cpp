/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
// 1. 哈希表
// 2023-08-03 submission
// 83/83 cases passed
// Runtime: 6 ms, faster than 89.1% of cpp online submissions.
// Memory Usage: 9.1 MB, less than 67.36% of cpp online submissions.
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> hash(26, INT_MAX);
        for (const string& word : words) {
            vector<int> temp(26, 0);
            for (const char& c : word) {
                temp[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                hash[i] = min(hash[i], temp[i]);
            }
        }
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < hash[i]; j++) {
                res.push_back(string(1, i + 'a'));
            }
        }
        return res;
    }
};
// @lc code=end
