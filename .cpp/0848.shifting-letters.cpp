/*
 * @lc app=leetcode id=848 lang=cpp
 *
 * [848] Shifting Letters
 */

// @lc code=start
// 1. 反向累加和数组
// 2023-09-27 submission
// 53/53 cases passed
// Runtime: 117 ms, faster than 17.04% of cpp online submissions.
// Memory Usage: 70.9 MB, less than 20.51% of cpp online submissions.
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        vector<int> sum(n);
        sum[n - 1] = shifts[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            sum[i] = (sum[i + 1] + shifts[i]) % 26;
        }
        for (int i = 0; i < n; ++i) {
            int d = s[i] - 'a';
            s[i] = 'a' + (d + sum[i]) % 26;
        }
        return s;
    }
};
// @lc code=end
