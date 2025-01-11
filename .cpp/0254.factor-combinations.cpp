/*
 * @lc app=leetcode id=254 lang=cpp
 *
 * [254] Factor Combinations
 */

// @lc code=start
// 1. 递归回溯
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> out;
        dfs(n, 2, out, res);
        return res;
    }

    void dfs(int n, int start, vector<int>& out, vector<vector<int>>& res) {
        if (n == 1) {
            if (out.size() > 1) {
                res.push_back(out);
            }
            return;
        }

        for (int i = start; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                out.push_back(i);
                dfs(n / i, i, out, res);
                out.pop_back();
            }
        }

        out.push_back(n);
        dfs(1, n, out, res);
        out.pop_back();
    }
};
// @lc code=end
