/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (68.00%)
 * Likes:    8335
 * Dislikes: 287
 * Total Accepted:    1.4M
 * Total Submissions: 2.1M
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers nums, every element appears twice except
 * for one. Find that single one.
 * 
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 * 
 * 
 * Example 1:
 * Input: nums = [2,2,1]
 * Output: 1
 * Example 2:
 * Input: nums = [4,1,2,1,2]
 * Output: 4
 * Example 3:
 * Input: nums = [1]
 * Output: 1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4
 * Each element in the array appears twice except for one element which appears
 * only once.
 * 
 * 
 */

// @lc solution=start
题目描述：非空数组，除了 X 只出现一次其他所有元素都出现了两次，找出 X。

解题思路

1. 位操作：两个相同的数取异或(^)结果为0，所以对所有数取异或，结果即为 X
// @lc solution=end

// @lc code=start
// 2018-09-19 submission
// 61/61 cases passed
// Runtime: 12 ms, faster than 97.92% of C++ online submissions.
// Memory Usage: 17 MB, less than 19.36% of C++ online submissions.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
    }
};
// @lc code=end

