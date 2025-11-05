/*
 * @lc app=leetcode id=259 lang=cpp
 *
 * [259] 3Sum Smaller
 */

// @lc code=start
// 1. 排序+双指针
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < target) {
                    res += right - left;
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
