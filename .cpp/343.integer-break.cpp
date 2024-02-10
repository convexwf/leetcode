/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
// 2023-02-27 submission
// 50/50 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6 MB, less than 86.88% of C++ online submissions.
class Solution {
public:
    int integerBreak(int n) {
        int res = 0;
        for (int k = 2; k <= n; ++k) {
            int factor = n / k, tmp = 1;
            for (int i = 0; i < n % k; ++i) {
                tmp *= (factor + 1);
            }
            for (int i = 0; i < k - n % k; ++i) {
                tmp *= factor;
            }
            if (tmp > res)
                res = tmp;
            else
                return res;
        }
        return res;
    }
};
// @lc code=end