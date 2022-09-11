/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (50.54%)
 * Likes:    3373
 * Dislikes: 870
 * Total Accepted:    508.7K
 * Total Submissions: 1M
 * Testcase Example:  '00000010100101000001111010011100'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * Note:
 *
 *
 * Note that in some languages, such as Java, there is no unsigned integer
 * type. In this case, both input and output will be given as a signed integer
 * type. They should not affect your implementation, as the integer's internal
 * binary representation is the same, whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement
 * notation. Therefore, in Example 2 above, the input represents the signed
 * integer -3 and the output represents the signed integer -1073741825.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: n = 00000010100101000001111010011100
 * Output:    964176192 (00111001011110000010100101000000)
 * Explanation: The input binary string 00000010100101000001111010011100
 * represents the unsigned integer 43261596, so return 964176192 which its
 * binary representation is 00111001011110000010100101000000.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 11111111111111111111111111111101
 * Output:   3221225471 (10111111111111111111111111111111)
 * Explanation: The input binary string 11111111111111111111111111111101
 * represents the unsigned integer 4294967293, so return 3221225471 which its
 * binary representation is 10111111111111111111111111111111.
 *
 *
 *
 * Constraints:
 *
 *
 * The input must be a binary string of length 32
 *
 *
 *
 * Follow up: If this function is called many times, how would you optimize it?
 *
 */

// @lc code=start
// 2022-07-30 submission
// 600/600 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6 MB, less than 11.13% of C++ online submissions.
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0u;
        for(int i = 0; i < 32; i++) {
            ret = ret << 1;
            if(n & 1 == 1) ret += 1;
            n = n >> 1;
        }
        return ret;
    }
};
// @lc code=end

// @lc code=start
// forum
// https://leetcode.com/problems/reverse-bits/discuss/54741/O(1)-bit-operation-C++-solution-(8ms)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
// for 8 bit binary number abcdefgh, the process is as follow:
// abcdefgh -> efghabcd -> ghefcdab -> hgfedcba
// @lc code=end
