/*
 * @lc app=leetcode id=1217 lang=cpp
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
 */

// @lc code=start
// 1. 模拟
// 2020-11-06 submission
// 51/51 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 9.9 MB, less than 73.63% of cpp online submissions.
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (int i = 0; i < position.size(); i++) {
            if (position[i] % 2 == 0) {
                even++;
            }
            else {
                odd++;
            }
        }
        return min(odd, even);
    }
};
// @lc code=end
