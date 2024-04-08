/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
// 2022-11-17 submission
// 193/193 cases passed
// Runtime: 4 ms, faster than 93.98% of cpp online submissions.
// Memory Usage: 12.3 MB, less than 69.47% of cpp online submissions.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            else
                --right;
        }
        return nums[right];
    }
};
// @lc code=end

// @lc code=start
// 2022-11-17 submission
// 193/193 cases passed
// Runtime: 12 ms, faster than 55.04% of cpp online submissions.
// Memory Usage: 12.2 MB, less than 94.2% of cpp online submissions.
class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums, 0, (int)nums.size() - 1);
    }
    int helper(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        if (nums[start] < nums[end]) return nums[start];
        int mid = (start + end) / 2;
        return min(helper(nums, start, mid), helper(nums, mid + 1, end));
    }
};
// @lc code=end
