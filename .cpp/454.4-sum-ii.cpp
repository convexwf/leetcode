/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
// 2020-12-18 submission
// 132/132 cases passed
// Runtime: 304 ms, faster than 70.29% of cpp online submissions.
// Memory Usage: 24.2 MB, less than 95.67% of cpp online submissions.
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> m;
        for (int a : A) {
            for (int b : B) {
                ++m[a + b];
            }
        }
        for (int c : C) {
            for (int d : D) {
                if (m.count(-c - d)) res += m[-c - d];
            }
        }
        return res;
    }
};
// @lc code=end
