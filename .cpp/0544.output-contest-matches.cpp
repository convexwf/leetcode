/*
 * @lc app=leetcode id=544 lang=cpp
 *
 * [544] Output Contest Matches
 */

// @lc code=start
// 1. 模拟
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> teams(n);
        for (int i = 0; i < n; ++i) {
            teams[i] = to_string(i + 1);
        }
        while (n > 1) {
            for (int i = 0; i < n / 2; ++i) {
                teams[i] = "(" + teams[i] + "," + teams[n - i - 1] + ")";
            }
            n /= 2;
        }
        return teams[0];
    }
};
// @lc code=end
