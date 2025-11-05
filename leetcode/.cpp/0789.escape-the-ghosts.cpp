/*
 * @lc app=leetcode id=789 lang=cpp
 *
 * [789] Escape The Ghosts
 */

// @lc code=start
// 1. 模拟
// 2023-07-05 submission
// 77/77 cases passed
// Runtime: 8 ms, faster than 53.47% of cpp online submissions.
// Memory Usage: 10.3 MB, less than 71.29% of cpp online submissions.
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int steps = abs(target[0]) + abs(target[1]);
        for (auto& ghost : ghosts) {
            int ghost_steps = abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]);
            if (ghost_steps <= steps) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
