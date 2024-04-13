/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
// 1. 贪心算法
// 2023-10-05 submission
// 290/290 cases passed
// Runtime: 2 ms, faster than 60.85% of cpp online submissions.
// Memory Usage:  MB, less than 77.52% of cpp online submissions.
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
        for (char c : s) {
            count[c - 'a']++;
        }
        string res = "";
        for (char c : s) {
            count[c - 'a']--;
            if (visited[c - 'a']) continue;
            while (!res.empty() && res.back() > c && count[res.back() - 'a'] > 0) {
                visited[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(c);
            visited[c - 'a'] = true;
        }
        return res;
    }
};
// @lc code=end
