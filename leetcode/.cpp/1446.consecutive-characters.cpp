/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
 */

// @lc code=start
// 1. 遍历计数
// 2020-11-04 submission
// 333/333 cases passed
// Runtime: 3 ms, faster than 63.12% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 16.57% of cpp online submissions.
class Solution {
public:
    int maxPower(string s) {
        if (s.length() <= 0) return 0;
        int res = 1, count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
                res = max(res, count);
            }
            else {
                count = 1;
            }
        }
        return res;
    }
};
// @lc code=end
