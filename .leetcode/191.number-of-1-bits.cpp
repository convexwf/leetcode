/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 *
 * https://leetcode.com/problems/number-of-1-bits/description/
 *
 * algorithms
 * Easy (57.45%)
 * Likes:    2419
 * Dislikes: 741
 * Total Accepted:    621.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '00000000000000000000000000001011'
 *
 * Write a function that takes an unsigned integer and returns the number of
 * '1' bits it has (also known as the Hamming weight).
 * 
 * Note:
 * 
 * 
 * Note that in some languages, such as Java, there is no unsigned integer
 * type. In this case, the input will be given as a signed integer type. It
 * should not affect your implementation, as the integer's internal binary
 * representation is the same, whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement
 * notation. Therefore, in Example 3, the input represents the signed integer.
 * -3.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 00000000000000000000000000001011
 * Output: 3
 * Explanation: The input binary string 00000000000000000000000000001011 has a
 * total of three '1' bits.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 00000000000000000000000010000000
 * Output: 1
 * Explanation: The input binary string 00000000000000000000000010000000 has a
 * total of one '1' bit.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 11111111111111111111111111111101
 * Output: 31
 * Explanation: The input binary string 11111111111111111111111111111101 has a
 * total of thirty one '1' bits.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The input must be a binary string of length 32.
 * 
 * 
 * 
 * Follow up: If this function is called many times, how would you optimize it?
 */

// @lc solution=start
位操作：从右往左的第一个 1 变为 0
// @lc solution=end

// @lc code=start
// 2018-07-26 submission
// 601/601 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 46.83% of C++ online submissions.
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        while(n) {
            num++;
            n &= n-1;
        }
        return num;
    }
};
// @lc code=end

