/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
// 1. brute force
// 2023-08-30 submission
// 48/48 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.9 MB, less than 13.72% of cpp online submissions.
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        if (s.empty()) return true;
        for (int i = 0; i < s.size(); ++i) {
            if (s.substr(i) + s.substr(0, i) == goal) return true;
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2. KMP 算法
// 2023-08-30 submission
// 48/48 cases passed
// Runtime: 2 ms, faster than 47.78% of cpp online submissions.
// Memory Usage: 6.1 MB, less than 63.51% of cpp online submissions.
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        if (s.empty()) return true;
        s += s;
        vector<int> next(s.size(), -1);
        for (int i = 1, j = -1; i < s.size(); ++i) {
            while (j != -1 && s[i] != s[j + 1]) j = next[j];
            if (s[i] == s[j + 1]) ++j;
            next[i] = j;
        }
        for (int i = 0, j = -1; i < s.size(); ++i) {
            while (j != -1 && s[i] != goal[j + 1]) j = next[j];
            if (s[i] == goal[j + 1]) ++j;
            if (j == goal.size() - 1) return true;
        }
        return false;
    }
};
// class Solution {
// public:
//     bool rotateString(string A, string B) {
//         return A.size() == B.size() && (A + A).find(B) != string::npos;
//     }
// };
// @lc code=end
