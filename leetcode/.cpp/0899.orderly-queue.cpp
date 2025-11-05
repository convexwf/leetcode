/*
 * @lc app=leetcode id=899 lang=cpp
 *
 * [899] Orderly Queue
 */

// @lc code=start
// 1. 模拟
// 2024-08-13 submission
// 112/112 cases passed
// Runtime: 7 ms, faster than 17.38% of cpp online submissions.
// Memory Usage: 12.8 MB, less than 35.22% of cpp online submissions.
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string res = s;
            for (int i = 1; i < s.size(); ++i) {
                res = min(res, s.substr(i) + s.substr(0, i));
            }
            return res;
        }
        sort(s.begin(), s.end());
        return s;
    }
};
// @lc code=end
