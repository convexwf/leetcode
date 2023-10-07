/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
// 2020-06-28 submission
// 79/79 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.2 MB, less than 69.13% of C++ online submissions.
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
        for (int i = 0; i <= m - n; ++i) {
            int j = 0;
            for (j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};
// @lc code=end
