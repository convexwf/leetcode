/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
// 1. 位操作
// 2023-01-30 submission
// 32/32 cases passed
// Runtime: 9 ms, faster than 82.46% of C++ online submissions.
// Memory Usage: 10 MB, less than 58.62% of C++ online submissions.
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> res(2, 0);
        for (int& a : nums) {
            if (a & diff) {
                res[0] ^= a;
            }
            else {
                res[1] ^= a;
            }
        }
        return res;
    }
};
// @lc code=end
