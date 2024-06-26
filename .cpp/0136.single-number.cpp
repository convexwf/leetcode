/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
// 1. 位操作
// 2018-09-19 submission
// 61/61 cases passed
// Runtime: 24 ms, faster than 76.56% of cpp online submissions.
// Memory Usage: 16.9 MB, less than 51.54% of cpp online submissions.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
    }
};
// @lc code=end
