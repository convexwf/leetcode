/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
// 2022-07-26 submission
// 87/87 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 70.19% of cpp online submissions.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = (int)nums.size() - 1;
        for (int i = 0; i <= r;) {
            if (nums[i] == 2) {
                swap(nums[i], nums[r--]);
            }
            else if (nums[i] == 0) {
                swap(nums[i], nums[l++]);
                ++i;
            }
            else {
                ++i;
            }
        }
    }
};
// @lc code=end
