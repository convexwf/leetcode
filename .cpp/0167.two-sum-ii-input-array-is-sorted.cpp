/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
// 1. 双指针
// 2022-11-14 submission
// 21/21 cases passed
// Runtime: 36 ms, faster than 27.96% of cpp online submissions.
// Memory Usage: 15.5 MB, less than 92.98% of cpp online submissions.
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() < 2) return {};
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                return {left + 1, right + 1};
            }
            else if (numbers[left] + numbers[right] < target) {
                ++left;
            }
            else {
                --right;
            }
        }
        return {};
    }
};
// @lc code=end

// @lc code=start
// 2. 二分查找
// 2024-06-19 submission
// 23/23 cases passed
// Runtime: 11 ms, faster than 36.42% of cpp online submissions.
// Memory Usage:  MB, less than 59.77% of cpp online submissions.
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == target - numbers[i]) {
                    return {i + 1, mid + 1};
                }
                else if (numbers[mid] < target - numbers[i]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return {};
    }
};
// @lc code=end
