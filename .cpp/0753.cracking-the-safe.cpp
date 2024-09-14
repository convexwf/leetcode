/*
 * @lc app=leetcode id=753 lang=cpp
 *
 * [753] Cracking the Safe
 */

// @lc code=start
// 1. 贪心算法+哈希表
// 2024-01-25 submission
// 38/38 cases passed
// Runtime: 6 ms, faster than 82.51% of cpp online submissions.
// Memory Usage: 10.3 MB, less than 47.26% of cpp online submissions.
class Solution {
public:
    string crackSafe(int n, int k) {
        string res(n, '0');
        unordered_set<string> visited;
        visited.insert(res);
        int total = pow(k, n);
        for (int i = 0; i < total; ++i) {
            string prev = res.substr(res.size() - n + 1, n - 1);
            for (int j = k - 1; j >= 0; --j) {
                string cur = prev + to_string(j);
                if (!visited.count(cur)) {
                    visited.insert(cur);
                    res += to_string(j);
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 欧拉回路
// 2024-01-25 submission
// 38/38 cases passed
// Runtime: 5 ms, faster than 84.33% of cpp online submissions.
// Memory Usage: 11.5 MB, less than 20.63% of cpp online submissions.
class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<int> vis;
        int mod = pow(10, n - 1);
        string ans;
        function<void(int)> dfs = [&](int u) {
            for (int x = 0; x < k; ++x) {
                int e = u * 10 + x;
                if (!vis.count(e)) {
                    vis.insert(e);
                    dfs(e % mod);
                    ans += (x + '0');
                }
            }
        };
        dfs(0);
        ans += string(n - 1, '0');
        return ans;
    }
};
// @lc code=end
