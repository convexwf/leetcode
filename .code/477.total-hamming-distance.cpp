/*
 * @lc app=leetcode id=477 lang=cpp
 *
 * [477] Total Hamming Distance
 *
 * https://leetcode.com/problems/total-hamming-distance/description/
 *
 * algorithms
 * Medium (52.12%)
 * Likes:    1767
 * Dislikes: 82
 * Total Accepted:    91.6K
 * Total Submissions: 175.8K
 * Testcase Example:  '[4,14,2]'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 *
 * Given an integer array nums, return the sum of Hamming distances between all
 * the pairs of the integers in nums.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [4,14,2]
 * Output: 6
 * Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is
 * 0010 (just
 * showing the four bits relevant in this case).
 * The answer will be:
 * HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2
 * + 2 + 2 = 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,14,4]
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^9
 * The answer for the given input will fit in a 32-bit integer.
 *
 *
 */

// @lc code=start
// 2022-08-26 submission
// 46/46 cases passed
// Runtime: 58 ms, faster than 89.55% of C++ online submissions.
// Memory Usage: 19.1 MB, less than 7.69% of C++ online submissions.
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
