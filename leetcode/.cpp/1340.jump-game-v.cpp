/*
 * @lc app=leetcode id=1340 lang=cpp
 *
 * [1340] Jump Game V
 */

// @lc code=start
// 1. 记忆化搜索
// 2025-03-27 submission
// 127/127 cases passed
// Runtime: 35 ms, faster than 20.93% of cpp online submissions.
// Memory Usage: 20.4 MB, less than 28.17% of cpp online submissions.
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> memo(n, -1);
        function<int(int)> dfs = [&](int i) {
            if (memo[i] != -1) {
                return memo[i];
            }
            int res = 1;
            for (int j = i + 1; j <= min(i + d, n - 1) && arr[j] < arr[i]; ++j) {
                res = max(res, 1 + dfs(j));
            }
            for (int j = i - 1; j >= max(i - d, 0) && arr[j] < arr[i]; --j) {
                res = max(res, 1 + dfs(j));
            }
            return memo[i] = res;
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};
// @lc code=end
