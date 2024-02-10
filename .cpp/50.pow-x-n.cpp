/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
// 2022-07-21 submission
// 305/305 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.8 MB, less than 79.99% of C++ online submissions.
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == -1) return 1 / x;
        double temp = myPow(x, n/2);
        if(n % 2 != 0) return temp * temp * myPow(x, n%2);
        else return temp * temp;
    }
};
// @lc code=end
