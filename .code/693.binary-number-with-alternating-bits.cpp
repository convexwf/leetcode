/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 *
 * https://leetcode.com/problems/binary-number-with-alternating-bits/description/
 *
 * algorithms
 * Easy (61.29%)
 * Likes:    1074
 * Dislikes: 104
 * Total Accepted:    104.3K
 * Total Submissions: 170.2K
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
 *
 */

// @lc code=start
// 2022-11-17 submission
// 204/204 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 69.74% of C++ online submissions.
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int d = n & 1;
        while ((n & 1) == d) {
            d ^= 1;
            n >>= 1;
        }
        return n == 0;
    }
};
// @lc code=end

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

// @lc code=start
// 2022-11-17 submission
// 204/204 cases passed
// Runtime: 3 ms, faster than 39.85% of C++ online submissions.
// Memory Usage: 6 MB, less than 28.41% of C++ online submissions.
class Solution {
public:
    bool hasAlternatingBits(int n) {
        return ((n ^= n / 4) & (n - 1)) == 0;
    }
};
// @lc code=end