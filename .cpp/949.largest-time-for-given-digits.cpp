/*
 * @lc app=leetcode id=949 lang=cpp
 *
 * [949] Largest Time for Given Digits
 */

// @lc code=start
// 1. 枚举
// 2023-11-23 submission
// 172/172 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 47.53% of cpp online submissions.
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string res = "";
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    if (i == j || i == k || j == k) continue;
                    string hh = to_string(arr[i]) + to_string(arr[j]);
                    string mm = to_string(arr[k]) + to_string(arr[6 - i - j - k]);
                    string t = hh + ":" + mm;
                    if (hh < "24" && mm < "60" && t > res) res = t;
                }
            }
        }
        return res;
    }
};
// @lc code=end
