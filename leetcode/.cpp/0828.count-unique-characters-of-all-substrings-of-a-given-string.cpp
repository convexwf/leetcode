/*
 * @lc app=leetcode id=828 lang=cpp
 *
 * [828] Count Unique Characters of All Substrings of a Given String
 */

// @lc code=start
// 1. 哈希表
// 2025-06-06 submission
// 76/76 cases passed
// Runtime: 11 ms, faster than 70.05% of cpp online submissions.
// Memory Usage: 27.6 MB, less than 21.01% of cpp online submissions.
class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> pos(26, {-1});
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - 'A'].push_back(i);
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            pos[i].push_back(s.size());
            for (int j = 1; j < pos[i].size() - 1; ++j) {
                int left = pos[i][j] - pos[i][j - 1];
                int right = pos[i][j + 1] - pos[i][j];
                res += left * right;
            }
        }
        return res;
    }
};
// @lc code=end
