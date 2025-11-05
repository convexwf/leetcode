/*
 * @lc app=leetcode id=932 lang=cpp
 *
 * [932] Beautiful Array
 */

// @lc code=start
// 1. 分治法
// 2025-02-10 submission
// 38/38 cases passed
// Runtime: 2 ms, faster than 44.21% of cpp online submissions.
// Memory Usage: 9.7 MB, less than 88.13% of cpp online submissions.
class Solution {
public:
    vector<int> beautifulArray(int N) {
        if (N == 1) {
            return {1};
        }
        vector<int> sub = beautifulArray(N / 2 + N % 2);
        vector<int> res;
        for (int i = 0; i < sub.size(); ++i) {
            if (sub[i] * 2 - 1 <= N) {
                res.push_back(sub[i] * 2 - 1);
            }
        }
        for (int i = 0; i < sub.size(); ++i) {
            if (sub[i] * 2 <= N) {
                res.push_back(sub[i] * 2);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 迭代构造
// 2023-09-21 submission
// 38/38 cases passed
// Runtime: 2 ms, faster than 64.62% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 42.11% of cpp online submissions.
class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res = {1};
        while (res.size() < n) {
            vector<int> tmp;
            for (int i : res) {
                if (i * 2 - 1 <= n) {
                    tmp.push_back(i * 2 - 1);
                }
            }
            for (int i : res) {
                if (i * 2 <= n) {
                    tmp.push_back(i * 2);
                }
            }
            res = tmp;
        }
        return res;
    }
};
// @lc code=end
