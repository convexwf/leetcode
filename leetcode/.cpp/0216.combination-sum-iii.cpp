/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
// 1. 回溯
// 2023-01-14 submission
// 18/18 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.3 MB, less than 95.33% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> out;
        dfs(res, out, k, n, 1);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& out, int k, int n, int start) {
        if (n < 0) {
            return;
        }
        if (out.size() == k) {
            if (n == 0) {
                res.push_back(out);
            }
            return;
        }
        for (int i = start; i <= 9; ++i) {
            out.push_back(i);
            dfs(res, out, k, n - i, i + 1);
            out.pop_back();
        }
    }
};
// @lc code=end
