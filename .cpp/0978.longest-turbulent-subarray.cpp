/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 */

// @lc code=start
// 1. 动态规划
// 2023-02-18 submission
// 91/91 cases passed
// Runtime: 86 ms, faster than 60.44% of cpp online submissions.
// Memory Usage: 43.8 MB, less than 9.43% of cpp online submissions.
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> inc(n, 1);
        vector<int> dec(n, 1);
        int res = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                inc[i] = dec[i - 1] + 1;
                res = max(res, inc[i]);
            }
            else if (arr[i] < arr[i - 1]) {
                dec[i] = inc[i - 1] + 1;
                res = max(res, dec[i]);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划-空间优化
// 2023-02-18 submission
// 91/91 cases passed
// Runtime: 81 ms, faster than 76.89% of cpp online submissions.
// Memory Usage: 40.4 MB, less than 64.51% of cpp online submissions.
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int inc = 1, dec = 1, res = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                inc = dec + 1;
                dec = 1;
                res = max(res, inc);
            }
            else if (arr[i] < arr[i - 1]) {
                dec = inc + 1;
                inc = 1;
                res = max(res, dec);
            }
            else {
                inc = dec = 1;
            }
        }
        return res;
    }
};
// @lc code=end
