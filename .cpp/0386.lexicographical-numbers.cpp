/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
// 1. dfs
// 2023-06-06 submission
// 26/26 cases passed
// Runtime: 14 ms, faster than 56.39% of cpp online submissions.
// Memory Usage: 11.6 MB, less than 52.26% of cpp online submissions.
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; ++i) {
            dfs(i, n, res);
        }
        return res;
    }

    void dfs(int cur, int n, vector<int>& res) {
        if (cur > n) return;
        res.push_back(cur);
        for (int i = 0; i <= 9; ++i) {
            dfs(cur * 10 + i, n, res);
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 迭代
// 2023-06-06 submission
// 26/26 cases passed
// Runtime: 9 ms, faster than 77.68% of cpp online submissions.
// Memory Usage: 10.4 MB, less than 92.77% of cpp online submissions.
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = cur;
            if (cur * 10 <= n) {
                cur *= 10;
            }
            else {
                if (cur >= n) {
                    cur /= 10;
                }
                cur += 1;
                while (cur % 10 == 0) {
                    cur /= 10;
                }
            }
        }
        return res;
    }
};
// @lc code=end
