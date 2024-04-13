/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
// 1. 出入度计算
// 2023-07-11 submission
// 92/92 cases passed
// Runtime: 174 ms, faster than 94.63% of cpp online submissions.
// Memory Usage: 60.7 MB, less than 90.48% of cpp online submissions.
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1, 0);
        vector<int> out(n + 1, 0);
        for (auto& t : trust) {
            ++out[t[0]];
            ++in[t[1]];
        }
        for (int i = 1; i <= n; ++i) {
            if (in[i] == n - 1 && out[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
