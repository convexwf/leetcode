/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
// 1. 贪心算法
// 2022-07-20 submission
// 170/170 cases passed
// Runtime: 91 ms, faster than 67.74% of cpp online submissions.
// Memory Usage: 48.5 MB, less than 43.19% of cpp online submissions.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > mx) break;
            mx = max(mx, i + nums[i]);
            if (mx >= nums.size() - 1) return true;
        }
        return false;
    }
};
// @lc code=end
