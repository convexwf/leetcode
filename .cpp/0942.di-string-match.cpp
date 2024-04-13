/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 */

// @lc code=start
// 1. brute force
// 2023-09-25 submission
// 95/95 cases passed
// Runtime: 3 ms, faster than 84.67% of cpp online submissions.
// Memory Usage: 8.8 MB, less than 74.66% of cpp online submissions.
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.size();
        vector<int> res(n + 1);
        int l = 0, r = n;
        for (int i = 0; i < n; ++i) {
            if (S[i] == 'I') {
                res[i] = l++;
            }
            else {
                res[i] = r--;
            }
        }
        res[n] = l;
        return res;
    }
};
// @lc code=end
