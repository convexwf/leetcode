/*
 * @lc app=leetcode id=1332 lang=cpp
 *
 * [1332] Remove Palindromic Subsequences
 */

// @lc code=start
// 1. 贪心算法
// 2023-12-20 submission
// 48/48 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.5 MB, less than 44.14% of cpp online submissions.
class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) {
            return 0;
        }
        int n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - i - 1]) {
                return 2;
            }
        }
        return 1;
    }
};
// @lc code=end
