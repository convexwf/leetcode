/*
 * @lc app=leetcode id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 */

// @lc code=start
// 1. 字符串转换
// 2023-06-29 submission
// 308/308 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 53.74% of cpp online submissions.
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int i = 1;
        while (i < str.size() && str[i - 1] <= str[i]) {
            i++;
        }
        if (i < str.size()) {
            while (i > 0 && str[i - 1] > str[i]) {
                str[i - 1]--;
                i--;
            }
            for (i += 1; i < str.size(); i++) {
                str[i] = '9';
            }
        }
        return stoi(str);
    }
};
// @lc code=end
