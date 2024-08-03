/*
 * @lc app=leetcode id=477 lang=cpp
 *
 * [477] Total Hamming Distance
 */

// @lc code=start
// 1. 位操作
// 2022-08-26 submission
// 46/46 cases passed
// Runtime: 58 ms, faster than 89.55% of cpp online submissions.
// Memory Usage: 19.1 MB, less than 7.69% of cpp online submissions.
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                count += ((nums[j] >> i) & 1);
            }
            res += ((nums.size() - count) * count);
        }
        return res;
    }
};
// @lc code=end
