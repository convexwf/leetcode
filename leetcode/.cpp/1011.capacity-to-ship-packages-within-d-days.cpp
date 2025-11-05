/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
// 1. 二分查找
// 2023-10-25 submission
// 87/87 cases passed
// Runtime: 45 ms, faster than 82.33% of cpp online submissions.
// Memory Usage: 31.4 MB, less than 54.1% of cpp online submissions.
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (daysNeeded(weights, mid) > days) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }

private:
    int daysNeeded(vector<int>& weights, int capacity) {
        int days = 0;
        int cur = 0;
        for (int weight : weights) {
            if (cur + weight > capacity) {
                ++days;
                cur = 0;
            }
            cur += weight;
        }
        return ++days;
    }
};
// @lc code=end
