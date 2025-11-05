/*
 * @lc app=leetcode id=1007 lang=cpp
 *
 * [1007] Minimum Domino Rotations For Equal Row
 */

// @lc code=start
// 1. 贪心算法
// 2024-01-11 submission
// 84/84 cases passed
// Runtime: 104 ms, faster than 50.81% of cpp online submissions.
// Memory Usage: 111.9 MB, less than 87.2% of cpp online submissions.
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> top_cnt(7, 0), bottom_cnt(7, 0), same_cnt(7, 0);
        for (int i = 0; i < n; ++i) {
            ++top_cnt[tops[i]];
            ++bottom_cnt[bottoms[i]];
            if (tops[i] == bottoms[i]) {
                ++same_cnt[tops[i]];
            }
        }
        for (int i = 1; i <= 6; ++i) {
            if (top_cnt[i] + bottom_cnt[i] - same_cnt[i] == n) {
                return n - max(top_cnt[i], bottom_cnt[i]);
            }
        }
        return -1;
    }
};
// @lc code=end
