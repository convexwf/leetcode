/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
// 1. 两次遍历
// 2025-03-19 submission
// 44/44 cases passed
// Runtime: 21 ms, faster than 41.18% of cpp online submissions.
// Memory Usage: 21.5 MB, less than 52.32% of cpp online submissions.
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        string res = dominoes;
        vector<int> count(n, n);

        // from left to right
        int effect = -1;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'L') {
                effect = -1;
            }
            else if (dominoes[i] == 'R') {
                effect = 0;
            }
            else if (dominoes[i] == '.' && effect >= 0) {
                count[i] = ++effect;
                res[i] = 'R';
            }
        }

        // from right to left
        effect = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') {
                effect = 0;
            }
            else if (dominoes[i] == 'R') {
                effect = -1;
            }
            else if (dominoes[i] == '.' && effect >= 0) {
                ++effect;
                if (effect < count[i]) {
                    res[i] = 'L';
                }
                else if (effect == count[i]) {
                    res[i] = '.';
                }
            }
        }
        return res;
    }
};
// @lc code=end
