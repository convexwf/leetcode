/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
// 2022-11-17 submission
// 21/21 cases passed
// Runtime: 87 ms, faster than 10.29% of cpp online submissions.
// Memory Usage: 17.4 MB, less than 78.25% of cpp online submissions.
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size() && j < g.size(); ++i) {
            if (s[i] >= g[j]) ++j;
        }
        return j;
    }
};
// @lc code=end
