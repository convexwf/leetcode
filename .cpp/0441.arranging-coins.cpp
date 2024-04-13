/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
// 1. 二分查找
// 2023-05-29 submission
// 1335/1335 cases passed
// Runtime: 0 ms, faster than % of cpp online submissions.
// Memory Usage:  MB, less than % of cpp online submissions.
class Solution {
public:
    int arrangeCoins(int n) {
        int left = 0, right = n;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long sum = mid * (mid + 1) / 2;
            if (sum == n)
                return mid;
            else if (sum < n)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};
// @lc code=end

// @lc code=start
// 2. 数学方法
// 2023-05-29 submission
// 1335/1335 cases passed
// Runtime: 6 ms, faster than 53.82% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 93.35% of cpp online submissions.
class Solution {
public:
    int arrangeCoins(int n) {
        return (int)(sqrt(2 * (long long)n + 0.25) - 0.5);
    }
};
// @lc code=end