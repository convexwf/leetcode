/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (55.91%)
 * Likes:    11053
 * Dislikes: 435
 * Total Accepted:    1.1M
 * Total Submissions: 2M
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order red, white, and blue.
 *
 * We will use the integers 0, 1, and 2 to represent the color red, white, and
 * blue, respectively.
 *
 * You must solve this problem without using the library's sort function.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] is either 0, 1, or 2.
 *
 *
 *
 * Follow up: Could you come up with a one-pass algorithm using only constant
 * extra space?
 *
 */

// @lc code=start
// 2022-07-26 submission
// 87/87 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 8.2 MB, less than 70.19% of C++ online submissions.
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
