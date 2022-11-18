/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 *
 * https://leetcode.com/problems/perfect-number/description/
 *
 * algorithms
 * Easy (37.77%)
 * Likes:    707
 * Dislikes: 946
 * Total Accepted:    118.8K
 * Total Submissions: 314.6K
 * Testcase Example:  '28'
 *
 * A perfect number is a positive integer that is equal to the sum of its
 * positive divisors, excluding the number itself. A divisor of an integer x is
 * an integer that can divide x evenly.
 * 
 * Given an integer n, return true if n is a perfect number, otherwise return
 * false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num = 28
 * Output: true
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 * 1, 2, 4, 7, and 14 are all divisors of 28.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = 7
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num <= 10^8
 * 
 * 
 */

// @lc code=start
// 2022-11-17 submission
// 98/98 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 68.15% of C++ online submissions.
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for (int i = 1; i <= int(sqrt(num)); i++) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num) sum += (num / i);
            }
        }
        return sum == 2 * num;
    }
};
// @lc code=end