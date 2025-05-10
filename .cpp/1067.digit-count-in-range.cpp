/*
 * @lc app=leetcode id=1067 lang=cpp
 *
 * [1067] Digit Count in Range
 */

// @lc code=start
// 1. 分类讨论
class Solution {
public:
    int digitCount(int d, int low, int high) {
        return countDigit(d, high) - countDigit(d, low - 1);
    }

    int countDigit(int d, int x) {
        if (x < 0) return 0;
        if (x < 10) return x >= d ? 1 : 0;

        int count = 0;
        for (int i = 1; i <= x; i *= 10) {
            int left = x / (i * 10);
            int right = x % i;
            int cur = (x / i) % 10;

            if (cur > d) {
                count += (left + 1) * i;
            }
            else if (cur == d) {
                count += left * i + right + 1;
            }
            else {
                count += left * i;
            }

            if (d == 0) {
                count -= i;
            }
        }
        return count;
    }
};
// @lc code=end
