/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (42.27%)
 * Likes:    2571
 * Dislikes: 190
 * Total Accepted:    229.9K
 * Total Submissions: 543.8K
 * Testcase Example:  '5\n7'
 *
 * Given two integers left and right that represent the range [left, right],
 * return the bitwise AND of all numbers in this range, inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: left = 5, right = 7
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: left = 0, right = 0
 * Output: 0
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: left = 1, right = 2147483647
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= left <= right <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
// 2022-11-14 submission
// 8268/8268 cases passed
// Runtime: 24 ms, faster than 44.81% of C++ online submissions.
// Memory Usage: 6 MB, less than 32.15% of C++ online submissions.
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return (m << i);
    }
};
// @lc code=end