/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (38.21%)
 * Likes:    4736
 * Dislikes: 1917
 * Total Accepted:    543.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 *
 * Note: You must not use any built-in BigInteger library or convert the inputs
 * to integer directly.
 *
 *
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 *
 * Constraints:
 *
 *
 * 1 <= num1.length, num2.length <= 200
 * num1 and num2 consist of digits only.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 *
 *
 */

// @lc code=start
// 2022-07-29 submission
// 311/311 cases passed
// Runtime: 4 ms, faster than 91.9% of C++ online submissions.
// Memory Usage: 6.6 MB, less than 83.46% of C++ online submissions.
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string res(m + n, '0');
        int carry = 0;
        int idx = res.length() - 1;
        for (int i = 0; i < m + n - 1; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j >= m || i - j >= n) continue;
                carry += (num1[(m - 1) - j] - '0') * (num2[(n - 1) - (i - j)] - '0');
            }
            if (carry > 0) {
                idx = res.length() - i - 1;
                res[idx] = carry % 10 + '0';
            }
            carry /= 10;
        }
        res[0] = carry + '0';
        return carry > 0 ? res : res.substr(idx);
    }
};
// @lc code=end