/*
 * @lc app=leetcode id=625 lang=cpp
 *
 * [625] Minimum Factorization
 */

// @lc code=start
// 1. 贪心算法
class Solution {
public:
    int smallestFactorization(int num) {
        if (num == 1) return 1;
        long res = 0, mul = 1;
        for (int i = 9; i >= 2; i--) {
            while (num % i == 0) {
                num /= i;
                res += i * mul;
                mul *= 10;
            }
        }
        return num == 1 && res <= INT_MAX ? res : 0;
    }
};
// @lc code=end
