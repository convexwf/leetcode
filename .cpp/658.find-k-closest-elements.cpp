/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
// 1. 双指针
// 2023-08-25 submission
// 67/67 cases passed
// Runtime: 28 ms, faster than 89.38% of cpp online submissions.
// Memory Usage:  MB, less than 97.78% of cpp online submissions.
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while (right - left + 1 > k) {
            if (abs(arr[left] - x) > abs(arr[right] - x)) {
                left++;
            }
            else {
                right--;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};
// @lc code=end

// @lc code=start
// 2. 二分查找
// 2023-08-25 submission
// 67/67 cases passed
// Runtime: 24 ms, faster than 95.92% of cpp online submissions.
// Memory Usage: 31.2 MB, less than 79.24% of cpp online submissions.
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
// @lc code=end
