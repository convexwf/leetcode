/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 */

// @lc code=start
// 1. 数学方法+记忆化搜索
// 2025-06-15 submission
// 151/151 cases passed
// Runtime: 39 ms, faster than 7.67% of cpp online submissions.
// Memory Usage: 14.3 MB, less than 5.23% of cpp online submissions.
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> f(k);
        function<double(int)> dfs = [&](int i) -> double {
            if (i >= k) {
                return i <= n ? 1 : 0;
            }
            if (i == k - 1) {
                return min(n - k + 1, maxPts) * 1.0 / maxPts;
            }
            if (f[i]) {
                return f[i];
            }
            return f[i] = dfs(i + 1) + (dfs(i + 1) - dfs(i + maxPts + 1)) / maxPts;
        };
        return dfs(0);
    }
};
// @lc code=end
