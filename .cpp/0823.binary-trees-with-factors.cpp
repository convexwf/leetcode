/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 */

// @lc code=start
// 1. 动态规划
// 2023-07-24 submission
// 48/48 cases passed
// Runtime: 73 ms, faster than 72.2% of cpp online submissions.
// Memory Usage: 9.1 MB, less than 91.89% of cpp online submissions.
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        long res = 0, M = 1e9 + 7;
        unordered_map<int, long> dp;
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size(); ++i) {
            dp[A[i]] = 1;
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0 && dp.count(A[i] / A[j])) {
                    dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % M;
                }
            }
        }
        for (auto a : dp) res = (res + a.second) % M;
        return res;
    }
};
// @lc code=end
