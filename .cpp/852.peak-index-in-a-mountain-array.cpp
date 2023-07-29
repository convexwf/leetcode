/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
// 1. 线性遍历
// 2023-07-27 submission
// 42/42 cases passed
// Runtime: 126 ms, faster than 60.35% of cpp online submissions.
// Memory Usage: 59.6 MB, less than 85.49% of cpp online submissions.
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) {
                return i - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

// @lc code=start
// 2. 二分查找
// 2023-07-27 submission
// 42/42 cases passed
// Runtime: 119 ms, faster than 82.67% of cpp online submissions.
// Memory Usage: 59.7 MB, less than 8.13% of cpp online submissions.
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
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
