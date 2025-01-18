/*
 * @lc app=leetcode id=975 lang=cpp
 *
 * [975] Odd Even Jump
 */

// @lc code=start
// 1. 有序字典+记忆化搜索
// 2025-01-15 submission
// 65/65 cases passed
// Runtime: 87 ms, faster than 26.33% of cpp online submissions.
// Memory Usage: 39.4 MB, less than 31.24% of cpp online submissions.
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextOdd(n, -1), nextEven(n, -1);
        map<int, int> g;
        for (int i = n - 1; i >= 0; --i) {
            // lower_bound 返回第一个大于等于 arr[i] 的 iterator
            auto it = g.lower_bound(arr[i]);
            if (it != g.end()) {
                nextOdd[i] = it->second;
            }
            // upper_bound 返回第一个大于 arr[i] 的 iterator
            auto it2 = g.upper_bound(arr[i]);
            if (it2 != g.begin()) {
                nextEven[i] = prev(it2)->second;
            }
            g[arr[i]] = i;
        }
        vector<vector<int>> memo(n, vector<int>(2, -1));
        function<int(int, bool)> dfs = [&](int i, bool odd) {
            if (i == n - 1) {
                return 1;
            }
            if (memo[i][odd] != -1) {
                return memo[i][odd];
            }
            int res = 0;
            if (odd) {
                if (nextOdd[i] != -1) {
                    res = dfs(nextOdd[i], false);
                }
            }
            else {
                if (nextEven[i] != -1) {
                    res = dfs(nextEven[i], true);
                }
            }
            return memo[i][odd] = res;
        };
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (dfs(i, true)) {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
