/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
// 1. 双指针
// 2024-07-25 submission
// 317/317 cases passed
// Runtime: 2 ms, faster than 71.51% of cpp online submissions.
// Memory Usage: 8.5 MB, less than 57.94% of cpp online submissions.
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string res = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int sum = x + y + add;
            res.push_back('0' + sum % 10);
            add = sum / 10;
            i--, j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
