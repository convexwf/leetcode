/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */

// @lc code=start
// 1. 枚举
// 2023-08-01 submission
// 137/137 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.8 MB, less than 96.15% of cpp online submissions.
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string s = to_string(N);
        sort(s.begin(), s.end());
        for (int i = 0; i < 31; ++i) {
            string t = to_string(1 << i);
            sort(t.begin(), t.end());
            if (s == t) return true;
        }
        return false;
    }
};
// @lc code=end
