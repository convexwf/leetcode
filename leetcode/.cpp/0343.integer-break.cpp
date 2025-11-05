/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
// 1. 找规律
// 2023-02-27 submission
// 50/50 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6 MB, less than 86.88% of cpp online submissions.
class Solution {
public:
    int integerBreak(int n) {
        int res = 1;
        for (int k = 2; k <= n; ++k) {
            int a = n / k, b = n % k;
            int cur = pow(a, k - b) * pow(a + 1, b);
            if (cur < res) break;
            res = cur;
        }
        return res;
    }
};
// @lc code=end
