/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// 2022-11-17 submission
// 24/24 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.8 MB, less than 68.51% of C++ online submissions.

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
// @lc code=end
