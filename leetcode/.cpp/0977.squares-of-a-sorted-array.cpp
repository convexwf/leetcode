/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
// 1. 双指针
// 2024-11-21 submission
// 137/137 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 28.5 MB, less than 91.35% of cpp online submissions.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0, right = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[i] = nums[left] * nums[left];
                left++;
            }
            else {
                res[i] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    }
};
// @lc code=end
