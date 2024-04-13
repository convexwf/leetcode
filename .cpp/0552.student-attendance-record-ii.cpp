/*
 * @lc app=leetcode id=552 lang=cpp
 *
 * [552] Student Attendance Record II
 */

// @lc code=start
// 1. 记忆化搜索
// 2024-01-18 submission
// 59/59 cases passed
// Runtime: 1539 ms, faster than 27.2% of cpp online submissions.
// Memory Usage: 395.1 MB, less than 30.63% of cpp online submissions.
class Solution {
public:
    const int mod = 1e9 + 7;

    int checkRecord(int n) {
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return dfs(n, 0, 0, memo);
    }

    int dfs(int n, int absent, int late, vector<vector<vector<int>>>& memo) {
        if (absent >= 2) return 0;
        if (late >= 3) return 0;
        if (n == 0) return 1; // must put this line after the above two lines
        if (memo[n][absent][late] != -1) return memo[n][absent][late];
        int ans = 0;
        ans = (ans + dfs(n - 1, absent, 0, memo)) % mod;
        ans = (ans + dfs(n - 1, absent + 1, 0, memo)) % mod;
        ans = (ans + dfs(n - 1, absent, late + 1, memo)) % mod;
        return memo[n][absent][late] = ans;
    }
};
// @lc code=end
