/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
// 2022-11-14 submission
// 44/44 cases passed
// Runtime: 13 ms, faster than 61.8% of cpp online submissions.
// Memory Usage: 6.9 MB, less than 91.41% of cpp online submissions.
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
// @lc code=end
