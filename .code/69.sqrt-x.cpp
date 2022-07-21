/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (36.74%)
 * Likes:    4321
 * Dislikes: 3380
 * Total Accepted:    1.1M
 * Total Submissions: 3.1M
 * Testcase Example:  '4'
 *
 * Given a non-negative integer x, compute and return the square root of x.
 *
 * Since the return type is an integer, the decimal digits are truncated, and
 * only the integer part of the result is returned.
 *
 * Note: You are not allowed to use any built-in exponent function or operator,
 * such as pow(x, 0.5) or x ** 0.5.
 *
 *
 * Example 1:
 *
 *
 * Input: x = 4
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: x = 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since the decimal part
 * is truncated, 2 is returned.
 *
 *
 * Constraints:
 *
 *
 * 0 <= x <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int64_t res = x;
        while (res * res > x) {
            res = (res + x / res) / 2;
        }
        return res;
    }
};
// @lc code=end

