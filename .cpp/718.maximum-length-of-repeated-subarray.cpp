/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
// 2023-02-13 submission
// 53/53 cases passed
// Runtime: 321 ms, faster than 34.56% of C++ online submissions.
// Memory Usage: 85.6 MB, less than 40.11% of C++ online submissions.
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0, m = A.size(), n = B.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (A[i - 1] == B[j - 1]) ? dp[i - 1][j - 1] + 1 : 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end