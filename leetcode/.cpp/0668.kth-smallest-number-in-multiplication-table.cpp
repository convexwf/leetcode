/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
 */

// @lc code=start
// 1. 二分查找
// 2024-01-23 submission
// 70/70 cases passed
// Runtime: 8 ms, faster than 80.19% of cpp online submissions.
// Memory Usage:  MB, less than 5.01% of cpp online submissions.
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for (int i = m, j = 1; i >= 1 && j <= n;) {
                if (i * j <= mid) {
                    cnt += i;
                    ++j;
                }
                else {
                    --i;
                }
            }
            if (cnt >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
