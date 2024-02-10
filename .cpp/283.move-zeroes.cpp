/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
// 2022-11-14 submission
// 74/74 cases passed
// Runtime: 20 ms, faster than 97.39% of C++ online submissions.
// Memory Usage: 19.3 MB, less than 14.58% of C++ online submissions.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                ++i;
                swap(nums[i], nums[j]);
            }
        }
    }
};
// @lc code=end