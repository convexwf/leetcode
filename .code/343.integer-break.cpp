/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (55.87%)
 * Likes:    3528
 * Dislikes: 359
 * Total Accepted:    224.3K
 * Total Submissions: 401.5K
 * Testcase Example:  '2'
 *
 * Given an integer n, break it into the sum of k positive integers, where k >=
 * 2, and maximize the product of those integers.
 *
 * Return the maximum product you can get.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 58
 *
 *
 */

// @lc code=start
// 2023-02-27 submission
// 50/50 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6 MB, less than 86.88% of C++ online submissions.
class Solution {
public:
    int integerBreak(int n) {
        int res = 0;
        for (int k = 2; k <= n; ++k) {
            int factor = n / k, tmp = 1;
            for (int i = 0; i < n % k; ++i) {
                tmp *= (factor + 1);
            }
            for (int i = 0; i < k - n % k; ++i) {
                tmp *= factor;
            }
            if (tmp > res)
                res = tmp;
            else
                return res;
        }
        return res;
    }
};
// @lc code=end