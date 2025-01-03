/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
// 1. 递归回溯
// 2022-07-26 submission
// 27/27 cases passed
// Runtime: 44 ms, faster than 49.19% of cpp online submissions.
// Memory Usage: 8.9 MB, less than 91.31% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out;
        dfs(n, k, 1, out, res);
        return res;
    }

    void dfs(int n, int k, int level, vector<int>& out, vector<vector<int>>& res) {
        if (out.size() == k) {
            res.push_back(out);
            return;
        }
        for (int i = level; i <= n; ++i) {
            out.push_back(i);
            dfs(n, k, i + 1, out, res);
            out.pop_back();
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 分治法
// 2022-07-26 submission
// 27/27 cases passed
// Runtime: 59 ms, faster than 32.36% of cpp online submissions.
// Memory Usage: 34.1 MB, less than 24.7% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k > n || k < 0) return {};
        if (k == 0) return {{}};
        vector<vector<int>> res = combine(n - 1, k - 1);
        for (vector<int>& a : res) {
            a.push_back(n);
        }
        for (vector<int>& a : combine(n - 1, k)) {
            res.push_back(a);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 迭代
// 2024-12-18 submission
// 27/27 cases passed
// Runtime: 35 ms, faster than 95.37% of cpp online submissions.
// Memory Usage: 62.3 MB, less than 67.89% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out(k, 0);
        int i = 0;
        while (i >= 0) {
            ++out[i];
            if (out[i] > n) {
                --i;
            }
            else if (i == k - 1) {
                res.push_back(out);
            }
            else {
                ++i;
                out[i] = out[i - 1];
            }
        }
        return res;
    }
};
// @lc code=end
