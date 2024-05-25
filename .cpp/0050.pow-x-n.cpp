/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
// 1. 分治递归
// 2022-07-21 submission
// 305/305 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.8 MB, less than 79.99% of cpp online submissions.
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1 / x;
        double temp = myPow(x, n / 2);
        if (n % 2 != 0)
            return temp * temp * myPow(x, n % 2);
        else
            return temp * temp;
    }
};
// @lc code=end

// @lc code=start
// 2. 数学方法(快速幂)+位操作
// 2024-05-21 submission
// 307/307 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 73.65% of cpp online submissions.
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        while (N) {
            if (N & 1) {
                ans *= x;
            }
            x *= x;
            N >>= 1;
        }
        return ans;
    }
};
// @lc code=end
