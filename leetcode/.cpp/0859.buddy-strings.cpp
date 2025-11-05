/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
// 1. 字符串处理
// 2023-07-28 submission
// 39/39 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.2 MB, less than 7.06% of cpp online submissions.
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        if (s == goal) {
            unordered_set<char> s_set(s.begin(), s.end());
            return s_set.size() < s.size();
        }

        vector<int> diff;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                diff.push_back(i);
            }
            if (diff.size() > 2) {
                return false;
            }
        }

        return diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
    }
};
// @lc code=end
