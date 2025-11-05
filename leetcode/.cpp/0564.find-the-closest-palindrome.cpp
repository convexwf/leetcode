/*
 * @lc app=leetcode id=564 lang=cpp
 *
 * [564] Find the Closest Palindrome
 */

// @lc code=start
// 1. 分类讨论
// 2024-01-09 submission
// 217/217 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.2 MB, less than 8.71% of cpp online submissions.
class Solution {
public:
    string nearestPalindromic(string n) {
        long len = n.size(), num = stol(n), res, minDiff = LONG_MAX;
        unordered_set<long> s;
        s.insert(pow(10, len) + 1);
        s.insert(pow(10, len - 1) - 1);
        long prefix = stol(n.substr(0, (len + 1) / 2));
        for (long i = -1; i <= 1; ++i) {
            string pre = to_string(prefix + i);
            string str = pre + string(pre.rbegin() + (len & 1), pre.rend());
            s.insert(stol(str));
        }
        s.erase(num);
        for (auto a : s) {
            long diff = abs(a - num);
            if (diff < minDiff) {
                minDiff = diff;
                res = a;
            }
            else if (diff == minDiff) {
                res = min(res, a);
            }
        }
        return to_string(res);
    }
};
// @lc code=end
