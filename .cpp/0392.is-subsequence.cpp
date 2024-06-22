/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
// 1. 双指针
// 2022-11-14 submission
// 18/18 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.4 MB, less than 67.45% of cpp online submissions.
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_i = 0;
        for (int i = 0; i < t.length() && s_i < s.length(); i++) {
            if (t[i] == s[s_i]) s_i++;
        }
        return s_i == s.length();
    }
};
// @lc code=end

// @lc code=start
// Follow up
// 2022-11-14 submission
// 18/18 cases passed
// Runtime: 11 ms, faster than 7.87% of cpp online submissions.
// Memory Usage: 6.8 MB, less than 10.46% of cpp online submissions.
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pre = -1, n = t.size();
        unordered_map<char, vector<int>> char2pos;
        for (int i = 0; i < n; ++i) char2pos[t[i]].push_back(i);
        for (char c : s) {
            auto it = upper_bound(char2pos[c].begin(), char2pos[c].end(), pre);
            if (it == char2pos[c].end()) return false;
            pre = *it;
        }
        return true;
    }
};
// @lc code=end
