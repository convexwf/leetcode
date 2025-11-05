/*
 * @lc app=leetcode id=2401 lang=cpp
 *
 * [2401] Longest Nice Subarray
 */

// @lc code=start
// 1. 位运算+滑动窗口
// 2024-01-19 submission
// 65/65 cases passed
// Runtime: 110 ms, faster than 39.85% of cpp online submissions.
// Memory Usage: 57.5 MB, less than 77.8% of cpp online submissions.
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int mask = 0;
        int left = 0, right = 0;
        int ans = 0;
        while (right < n) {
            while (mask & nums[right]) {
                mask &= ~nums[left];
                left++;
            }
            mask |= nums[right];
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
// @lc code=end
