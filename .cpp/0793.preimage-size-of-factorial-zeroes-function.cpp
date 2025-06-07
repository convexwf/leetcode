/*
 * @lc app=leetcode id=793 lang=cpp
 *
 * [793] Preimage Size of Factorial Zeroes Function
 */

// @lc code=start
// 1. 数学方法+二分查找
// 2025-06-04 submission
// 44/44 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.7 MB, less than 71.07% of cpp online submissions.
class Solution {
public:
    int preimageSizeFZF(int k) {
        return g(k + 1) - g(k);
    }

    int g(int k) {
        long left = 0, right = 1l * 5 * k;
        while (left < right) {
            long mid = (left + right) >> 1;
            if (f(mid) >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return (int)left;
    }

    int f(long x) {
        int res = 0;
        while (x) {
            x /= 5;
            res += x;
        }
        return res;
    }
};
// @lc code=end
