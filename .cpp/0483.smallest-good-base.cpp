/*
 * @lc app=leetcode id=483 lang=cpp
 *
 * [483] Smallest Good Base
 */

// @lc code=start
// 1. 数学方法+二分查找
// 2025-06-03 submission
// 109/109 cases passed
// Runtime: 2 ms, faster than 25.28% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 21.89% of cpp online submissions.
class Solution {
public:
    string smallestGoodBase(string n) {
        long num = stoll(n);
        for (int m = log(num + 1) / log(2); m >= 2; --m) {
            long left = 2, right = pow(num, 1.0 / m);
            while (left <= right) {
                long mid = left + (right - left) / 2;
                long sum = 1, base = 1;
                for (int i = 0; i < m; ++i) {
                    base *= mid;
                    sum += base;
                }
                if (sum == num) {
                    return to_string(mid);
                }
                else if (sum < num) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return to_string(num - 1);
    }
};
// @lc code=end
