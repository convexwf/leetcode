/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (57.12%)
 * Likes:    4384
 * Dislikes: 500
 * Total Accepted:    359.7K
 * Total Submissions: 629.7K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given an integer array nums where every element appears three times except
 * for one, which appears exactly once. Find the single element and return it.
 *
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 *
 *
 * Example 1:
 * Input: nums = [2,2,3,2]
 * Output: 3
 * Example 2:
 * Input: nums = [0,1,0,1,0,1,99]
 * Output: 99
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each element in nums appears exactly three times except for one element
 * which appears once.
 *
 *
 */

// @lc code=start
// 2022-07-23 submission
// 14/14 cases passed
// Runtime: 13 ms, faster than 55.33% of C++ online submissions.
// Memory Usage: 9.4 MB, less than 86.6% of C++ online submissions.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int idx = 0; idx < nums.size(); idx++) {
                sum += (nums[idx] >> i) & 1;
            }
            res += (sum % 3) << i; // |= or +=
        }
        return res;
    }
};
// @lc code=end