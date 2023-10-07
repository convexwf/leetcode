/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
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
