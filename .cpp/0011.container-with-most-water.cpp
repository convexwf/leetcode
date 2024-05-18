/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
// 1. 双指针
// 2023-02-28 submission
// 61/61 cases passed
// Runtime: 97 ms, faster than 73.42% of cpp online submissions.
// Memory Usage: 59.1 MB, less than 7.91% of cpp online submissions.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxValue = 0;
        int l = 0, r = (int)height.size() - 1;
        while (l < r) {
            int h = min(height[l], height[r]);
            maxValue = max(maxValue, h * (r - l));
            while (l < r && h >= height[l]) ++l;
            while (l < r && h >= height[r]) --r;
        }
        return maxValue;
    }
};
// @lc code=end
