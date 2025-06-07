/*
 * @lc app=leetcode id=466 lang=cpp
 *
 * [466] Count The Repetitions
 */

// @lc code=start
// 1. 递推
// 2025-06-06 submission
// 49/49 cases passed
// Runtime: 31 ms, faster than 38.21% of cpp online submissions.
// Memory Usage: 8.7 MB, less than 41.51% of cpp online submissions.
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int m = s1.size(), n = s2.size();
        vector<pair<int, int>> d;
        for (int i = 0; i < n; ++i) {
            int j = i;
            int cnt = 0;
            for (int k = 0; k < m; ++k) {
                if (s1[k] == s2[j]) {
                    if (++j == n) {
                        ++cnt;
                        j = 0;
                    }
                }
            }
            d.emplace_back(cnt, j);
        }
        int ans = 0;
        for (int j = 0; n1; --n1) {
            ans += d[j].first;
            j = d[j].second;
        }
        return ans / n2;
    }
};
// @lc code=end
