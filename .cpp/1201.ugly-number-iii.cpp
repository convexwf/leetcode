/*
 * @lc app=leetcode id=1201 lang=cpp
 *
 * [1201] Ugly Number III
 */

// @lc code=start
// 1. 二分查找+容斥原理
// 2024-02-10 submission
// 53/53 cases passed
// Runtime: 2 ms, faster than 44.66% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 9.09% of cpp online submissions.
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int left = 1, right = 2 * 1e9;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (count(mid, a, b, c) < n) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }

    long count(long x, long a, long b, long c) {
        return x / a + x / b + x / c - x / lcm(a, b) - x / lcm(b, c) - x / lcm(a, c) +
               x / lcm(a, b, c);
    }

    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    long lcm(long a, long b, long c) {
        return lcm(a, lcm(b, c));
    }
};
// @lc code=end
