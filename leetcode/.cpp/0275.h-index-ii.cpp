/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
// 1. 二分查找
// 2023-01-30 submission
// 83/83 cases passed
// Runtime: 21 ms, faster than 68.88% of cpp online submissions.
// Memory Usage: 18.7 MB, less than 52.49% of cpp online submissions.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] <= n - 1 - mid) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return n - right;
    }
};
// @lc code=end
