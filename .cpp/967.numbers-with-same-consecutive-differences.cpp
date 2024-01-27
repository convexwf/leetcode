/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

// @lc code=start
// 1. 递归
// 2024-01-22 submission
// 81/81 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 9.3 MB, less than 20.5% of cpp online submissions.
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for (int i = 1; i <= 9; ++i) {
            dfs(n, k, i, ans);
        }
        return ans;
    }

    void dfs(int n, int k, int num, vector<int>& ans) {
        if (n == 1) {
            ans.push_back(num);
            return;
        }
        int last = num % 10;
        if (last + k <= 9) {
            dfs(n - 1, k, num * 10 + last + k, ans);
        }
        if (last - k >= 0 && k != 0) {
            dfs(n - 1, k, num * 10 + last - k, ans);
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 迭代
// 2024-01-22 submission
// 81/81 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.7 MB, less than 49.03% of cpp online submissions.
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for (int i = 1; i <= 9; ++i) {
            ans.push_back(i);
        }
        for (int i = 1; i < n; ++i) {
            vector<int> tmp;
            for (int num : ans) {
                int last = num % 10;
                if (last + k <= 9) {
                    tmp.push_back(num * 10 + last + k);
                }
                if (last - k >= 0 && k != 0) {
                    tmp.push_back(num * 10 + last - k);
                }
            }
            ans = tmp;
        }
        return ans;
    }
};
// @lc code=end
