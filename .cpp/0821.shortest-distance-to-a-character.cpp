/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */

// @lc code=start
// 1. 记录位置
// 2023-05-30 submission
// 76/76 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.7 MB, less than 83.83% of cpp online submissions.
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> pos;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                pos.push_back(i);
            }
        }
        vector<int> res;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (j + 1 < pos.size() && abs(i - pos[j]) > abs(i - pos[j + 1])) {
                ++j;
            }
            res.push_back(abs(i - pos[j]));
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 双向遍历
// 2023-05-30 submission
// 76/76 cases passed
// Runtime: 6 ms, faster than 28.52% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 83.83% of cpp online submissions.
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> res(n, n);
        int pos = -n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) pos = i;
            res[i] = i - pos;
        }
        for (int i = pos - 1; i >= 0; --i) {
            if (s[i] == c) pos = i;
            res[i] = min(res[i], pos - i);
        }
        return res;
    }
};
// @lc code=end