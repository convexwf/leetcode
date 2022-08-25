/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (50.87%)
 * Likes:    5441
 * Dislikes: 588
 * Total Accepted:    882.6K
 * Total Submissions: 1.7M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings a and b, return their sum as a binary string.
 *
 *
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 *
 * Constraints:
 *
 *
 * 1 <= a.length, b.length <= 10^4
 * a and b consist only of '0' or '1' characters.
 * Each string does not contain leading zeros except for the zero itself.
 *
 *
 */

// @lc code=start
// 2022-07-27 submission
// 294/294 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.4 MB, less than 56.39% of C++ online submissions.
class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length();
        int blen = b.length();
        int rlen = max(alen, blen);

        string res(rlen, '1');
        int aval = 0;
        int bval = 0;
        int carry = 0;
        while (alen > 0 || blen > 0) {
            --alen; --blen;
            aval = (alen >= 0 ? (a[alen] - '0') : 0);
            bval = (blen >= 0 ? (b[blen] - '0') : 0);
            carry = carry + aval + bval;
            res[--rlen] = carry % 2 + '0';
            carry /= 2;
        }
        if (carry) return "1" + res;
        else return res;
    }
};
// @lc code=end