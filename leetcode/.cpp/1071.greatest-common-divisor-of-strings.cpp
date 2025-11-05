/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
// 1. 字符串处理
// 2023-10-24 submission
// 123/123 cases passed
// Runtime: 5 ms, faster than 47.51% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 24.47% of cpp online submissions.
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int len = gcd(str1.size(), str2.size());
        return str1.substr(0, len);
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
// @lc code=end
