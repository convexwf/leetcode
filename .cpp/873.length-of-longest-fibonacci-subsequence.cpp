/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start
// 1. 动态规划
// 2024-01-02 submission
// 57/57 cases passed
// Runtime: 681 ms, faster than 25.27% of cpp online submissions.
// Memory Usage: 146.2 MB, less than 17.22% of cpp online submissions.
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; ++i) {
            index[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 0;
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                int k = index.count(arr[j] - arr[i]) ? index[arr[j] - arr[i]] : -1;
                if (k >= 0 && k < i) {
                    dp[i][j] = max(dp[k][i] + 1, dp[i][j]);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans > 2 ? ans : 0;
    }
};
// @lc code=end
