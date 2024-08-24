/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
// 1. 双指针
// 2023-05-22 submission
// 60/60 cases passed
// Runtime: 4 ms, faster than 67.11% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 73.68% of cpp online submissions.
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            reverse(s.begin() + i, s.begin() + min(i + k, n));
        }
        return s;
    }
};
// @lc code=end
