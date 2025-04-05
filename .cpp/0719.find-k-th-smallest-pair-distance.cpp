/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
 */

// @lc code=start
// 1. 排序+二分查找+双指针
// 2025-04-02 submission
// 20/20 cases passed
// Runtime: 2 ms, faster than 70.16% of cpp online submissions.
// Memory Usage:  MB, less than 32.79% of cpp online submissions.
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countPairs(nums, mid) < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }

private:
    int countPairs(vector<int>& nums, int d) {
        int count = 0;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > d) {
                ++left;
            }
            count += right - left;
        }
        return count;
    }
};
// @lc code=end
