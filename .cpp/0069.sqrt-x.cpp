/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x, p = 0;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if ((long long)mid * mid <= x) {
                p = mid;
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return p;
    }
};
// @lc code=end
