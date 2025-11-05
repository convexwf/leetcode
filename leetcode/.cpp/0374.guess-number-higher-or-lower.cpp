/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
// 1. 二分查找
// 2022-11-14 submission
// 25/25 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 67.39% of cpp online submissions.
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            if (res == 0) {
                return mid;
            }
            else if (res == -1) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
