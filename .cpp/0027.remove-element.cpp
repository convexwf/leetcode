/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
// 1. 双指针
// 2022-08-07 submission
// 113/113 cases passed
// Runtime: 3 ms, faster than 68.33% of cpp online submissions.
// Memory Usage: 8.8 MB, less than 73.02% of cpp online submissions.
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int num : nums) {
            if (num != val) {
                nums[i++] = num;
            }
        }
        return i;
    }
};
// @lc code=end
