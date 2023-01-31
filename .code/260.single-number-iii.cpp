/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (67.27%)
 * Likes:    4077
 * Dislikes: 191
 * Total Accepted:    262.4K
 * Total Submissions: 390K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an integer array nums, in which exactly two elements appear only once
 * and all the other elements appear exactly twice. Find the two elements that
 * appear only once. You can return the answer in any order.
 * 
 * You must write an algorithm that runs in linear runtime complexity and uses
 * only constant extra space.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,1,3,2,5]
 * Output: [3,5]
 * Explanation:  [5, 3] is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-1,0]
 * Output: [-1,0]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [0,1]
 * Output: [1,0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each integer in nums will appear twice, only two integers will appear once.
 * 
 * 
 */

// @lc code=start
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
        for (int &a : nums) {
            if (a & diff) res[0] ^= a;
            else res[1] ^= a;
        }
        return res;
    }
};
// @lc code=end