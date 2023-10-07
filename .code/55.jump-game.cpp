/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
// 2022-07-20 submission
// 170/170 cases passed
// Runtime: 91 ms, faster than 67.74% of C++ online submissions.
// Memory Usage: 48.5 MB, less than 43.19% of C++ online submissions.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxIdx || maxIdx >= nums.size() - 1) break;
            maxIdx = max(maxIdx, i + nums[i]);
        }
        return maxIdx >= nums.size() - 1;
    }
};
// @lc code=end
