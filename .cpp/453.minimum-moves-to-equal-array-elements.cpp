/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 */

// @lc code=start
// 1. 数学方法
// 2023-05-26 submission
// 84/84 cases passed
// Runtime: 46 ms, faster than 49.48% of cpp online submissions.
// Memory Usage: 28.3 MB, less than 33.65% of cpp online submissions.
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ans += nums[i] - min_val;
        }
        return ans;
    }
};
// @lc code=end
