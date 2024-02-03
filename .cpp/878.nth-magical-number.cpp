/*
 * @lc app=leetcode id=878 lang=cpp
 *
 * [878] Nth Magical Number
 */

// @lc code=start
// 1. 数学方法+二分查找
// 2024-01-31 submission
// 70/70 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 100 MB, less than 12.81% of cpp online submissions.
class Solution {
public:
    const int MOD = 1000000007;
    using ull = unsigned long long;

    int nthMagicalNumber(int n, int a, int b) {
        ull lcm = (ull)a * b / gcd(a, b);
        ull l = 1, r = (ull)n * min(a, b);
        while (l < r) {
            ull mid = l + (r - l) / 2;
            ull cnt = mid / a + mid / b - mid / lcm;
            if (cnt < n) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l % MOD;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
// @lc code=end
