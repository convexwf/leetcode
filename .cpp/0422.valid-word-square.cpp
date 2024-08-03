/*
 * @lc app=leetcode id=422 lang=cpp
 *
 * [422] Valid Word Square
 */

// @lc code=start
// 1. 遍历检查
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i].size() != n) {
                return false;
            }
            for (int j = 0; j < n; ++j) {
                if (words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
