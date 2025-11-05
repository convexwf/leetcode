/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
// 1. 动态规划+单调递增栈
// 2025-06-08 submission
// 88/88 cases passed
// Runtime: 14 ms, faster than 74.68% of cpp online submissions.
// Memory Usage: 46.5 MB, less than 89.37% of cpp online submissions.
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long> dp(n, 0);
        stack<int> st;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                dp[i] = (i + 1) * arr[i];
            }
            else {
                int j = st.top();
                dp[i] = (i - j) * arr[i] + dp[j];
            }
            st.push(i);
            dp[i] %= MOD;
        }

        long result = 0;
        for (long long val : dp) {
            result = (result + val) % MOD;
        }
        return result;
    }
};
// @lc code=end
