/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

// @lc code=start
// 1. 数学方法
// 2023-09-01 submission
// 68/68 cases passed
// Runtime: 12 ms, faster than 79.38% of cpp online submissions.
// Memory Usage: 15.3 MB, less than 72.5% of cpp online submissions.
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
        return max(0, maxVal - minVal - 2 * k);
    }
};
// @lc code=end
