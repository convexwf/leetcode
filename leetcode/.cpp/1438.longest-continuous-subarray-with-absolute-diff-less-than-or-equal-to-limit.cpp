/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start
// 1. 滑动窗口+有序字典
// 2025-04-03 submission
// 63/63 cases passed
// Runtime: 91 ms, faster than 54.08% of cpp online submissions.
// Memory Usage: 93.9 MB, less than 38.78% of cpp online submissions.
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        map<int, int> count;
        int left = 0, right = 0;
        int maxLength = 0;
        while (right < n) {
            count[nums[right]]++;
            while (count.rbegin()->first - count.begin()->first > limit) {
                count[nums[left]]--;
                if (count[nums[left]] == 0) {
                    count.erase(nums[left]);
                }
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};
// @lc code=end
