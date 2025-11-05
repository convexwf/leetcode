/*
 * @lc app=leetcode id=822 lang=cpp
 *
 * [822] Card Flipping Game
 */

// @lc code=start
// 1. 哈希表
// 2023-07-24 submission
// 169/169 cases passed
// Runtime: 16 ms, faster than 85.4% of cpp online submissions.
// Memory Usage: 19.3 MB, less than 81.02% of cpp online submissions.
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int res = INT_MAX, n = fronts.size();
        unordered_set<int> same;
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                same.insert(fronts[i]);
            }
        }
        for (int front : fronts) {
            if (!same.count(front)) {
                res = min(res, front);
            }
        }
        for (int back : backs) {
            if (!same.count(back)) {
                res = min(res, back);
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};
// @lc code=end
