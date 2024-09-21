/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start
// 1. 状态机
// 2020-07-14 submission
// 1490/1490 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.8 MB, less than 100% of cpp online submissions.
class Solution {
public:
    bool isNumber(string s) {
        int trans[][4] = {{2, -1, 1, 3},     // 0
                          {2, -1, -1, 3},    // 1
                          {2, 5, -1, 4},     // 2
                          {4, -1, -1, -1},   // 3
                          {4, 5, -1, -1},    // 4
                          {7, -1, 6, -1},    // 5
                          {7, -1, -1, -1},   // 6
                          {7, -1, -1, -1},   // 7
                          {-1, -1, -1, -1}}; // 8
        int accepted[] = {2, 4, 7};

        s.append(1, ' ');
        int cur = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (cur == 0 || cur == 8) {
                    continue;
                }
                else if (cur == 2 || cur == 4 || cur == 7) {
                    cur = 8;
                }
                else {
                    cur = -1;
                }
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                cur = trans[cur][0];
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                cur = trans[cur][1];
            }
            else if (s[i] == '+' || s[i] == '-') {
                cur = trans[cur][2];
            }
            else if (s[i] == '.') {
                cur = trans[cur][3];
            }
            else {
                cur = -1;
            }
            if (cur == -1) return false;
        }
        return cur == 8;
    }
};
// @lc code=end
