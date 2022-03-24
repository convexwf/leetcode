/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 *
 * https://leetcode.com/problems/binary-number-with-alternating-bits/description/
 *
 * algorithms
 * Easy (60.54%)
 * Likes:    796
 * Dislikes: 98
 * Total Accepted:    85.4K
 * Total Submissions: 141K
 * Testcase Example:  '5'
 *
 * Given a positive integer, check whether it has alternating bits: namely, if
 * two adjacent bits will always have different values.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 5
 * Output: true
 * Explanation: The binary representation of 5 is: 101
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 7
 * Output: false
 * Explanation: The binary representation of 7 is: 111.
 * 
 * Example 3:
 * 
 * 
 * Input: n = 11
 * Output: false
 * Explanation: The binary representation of 11 is: 1011.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 1431655765
 */

// @lc solution=start
解题思路

1. 位运算：首先通过 `((n >> 1) ^ n)` 可以得到全 1 的数字，加 1 可得到 2 的整数次幂。

边界条件

1. n = 1431655765，经过 `((n >> 1) ^ n)` 后得到 INT_MAX，加 1 会溢出。
// @lc solution=end

// @lc code=start
// 2021-12-23 submission
// 204/204 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 62.97% of C++ online submissions.
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long x = ((n >> 1) ^ n);
        return (x & (x + 1)) == 0;
    }
};
// @lc code=end

