/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
// 2022-11-14 submission
// 1082/1082 cases passed
// Runtime: 13 ms, faster than 12.24% of C++ online submissions.
// Memory Usage: 7.2 MB, less than 12.34% of C++ online submissions.
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int sign = 1, base = 0, i = 0, n = str.size();
        while (i < n && str[i] == ' ') ++i;
        if (i < n && (str[i] == '+' || str[i] == '-')) {
            sign = (str[i++] == '+') ? 1 : -1;
        }
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            base = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};
// @lc code=end