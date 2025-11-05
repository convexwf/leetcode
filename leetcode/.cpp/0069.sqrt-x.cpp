/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
// 1. 二分查找
// 2024-12-30 submission
// 1017/1017 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.6 MB, less than 8.37% of cpp online submissions.
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int left = 0, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return right - 1;
    }
};
// @lc code=end

// @lc code=start
// 2. 牛顿迭代法
// 2024-12-30 submission
// 1017/1017 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.5 MB, less than 27.79% of cpp online submissions.
class Solution {
public:
    int mySqrt(int target) {
        if (target == 0) {
            return 0;
        }
        long x = target;
        while (x * x > target) {
            x = (x + target / x) / 2;
        }
        return x;
    }
};
// @lc code=end
