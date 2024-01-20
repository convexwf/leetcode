/*
 * @lc app=leetcode id=793 lang=cpp
 *
 * [793] Preimage Size of Factorial Zeroes Function
 */

// @lc code=start
class Solution {
public:
    int preimageSizeFZF(int k) {
        long left = 0, right = 5L * k + 5;
        while (left < right) {
            long mid = left + (right - left) / 2;
            if (f(mid) >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        if (f(left) != k) {
            return 0;
        }
        return (right + 1) - left;
    }

private:
    long f(long x) {
        long res = 0;
        while (x) {
            res += x / 5;
            x /= 5;
        }
        return res;
    }
};
// @lc code=end
