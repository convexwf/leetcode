/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (34.06%)
 * Likes:    1042
 * Dislikes: 1258
 * Total Accepted:    73.7K
 * Total Submissions: 216.4K
 * Testcase Example:  '13'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 13
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: n = 0
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 10^9
 *
 *
 */

// @lc code=start
// 2023-02-02 submission
// 38/38 cases passed
// Runtime: 3 ms, faster than 41.94% of C++ online submissions.
// Memory Usage: 5.8 MB, less than 94.5% of C++ online submissions.
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        long a = 1, b = 1; // n=1000000000 int 会溢出
        while (n > 0) {
            res += (n + 8) / 10 * a + (n % 10 == 1) * b;
            b += n % 10 * a;
            a *= 10;
            n /= 10;
        }
        return res;
    }
};
// @lc code=end