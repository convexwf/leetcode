/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
// 2022-07-27 submission
// 296/296 cases passed
// Runtime: 2 ms, faster than 63.11% of cpp online submissions.
// Memory Usage: 8.1 MB, less than 42.49% of cpp online submissions.
class Solution {
public:
    string addBinary(string a, string b) {
        int aidx = a.length();
        int bidx = b.length();
        int result_len = max(aidx, bidx);
        string result(result_len, '0');

        int carry = 0;
        while (aidx > 0 || bidx > 0) {
            --aidx;
            --bidx;
            int aval = (aidx >= 0 ? (a[aidx] - '0') : 0);
            int bval = (bidx >= 0 ? (b[bidx] - '0') : 0);
            result[--result_len] = (aval + bval + carry) % 2 + '0';
            carry = (aval + bval + carry) / 2;
        }
        if (carry > 0) return "1" + result;
        return result;
    }
};
// @lc code=end
