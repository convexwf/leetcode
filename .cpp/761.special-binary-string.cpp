/*
 * @lc app=leetcode id=761 lang=cpp
 *
 * [761] Special Binary String
 */

// @lc code=start
// 1. 递归+排序
// 2024-01-16 submission
// 87/87 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.8 MB, less than 47.86% of cpp online submissions.
class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.empty()) {
            return s;
        }
        int n = s.size();
        int cnt = 0, start = 0;
        vector<string> subs;
        for (int i = 0; i < n; ++i) {
            cnt += s[i] == '1' ? 1 : -1;
            if (cnt == 0) {
                string sub = s.substr(start + 1, i - start - 1);
                sub = '1' + makeLargestSpecial(sub) + '0';
                subs.push_back(sub);
                start = i + 1;
            }
        }
        sort(subs.begin(), subs.end(), greater<string>());
        string res;
        for (string& sub : subs) {
            res += sub;
        }
        return res;
    }
};
// @lc code=end
